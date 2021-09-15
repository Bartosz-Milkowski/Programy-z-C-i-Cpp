
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <omp.h>

using namespace std;

double start, stop, czas;
int iX, iY;
const int iXmax = 2000;
const int iYmax = 2000;

int tid;

unsigned char color[iXmax][iYmax][3];

double Cx, Cy;
const double CxMin = -2.5;
const double CxMax = 1.5;
const double CyMin = -2.0;
const double CyMax = 2.0;

double PixelWidth = (CxMax - CxMin) / iXmax;
double PixelHeight = (CyMax - CyMin) / iYmax;

const int MaxColorComponentValue = 255;

double Zx, Zy;
double Zx2, Zy2;

int Iteration;
const int IterationMax = 200;

const double EscapeRadius = 2;
double ER2 = EscapeRadius * EscapeRadius;


void funkcja()
{
	start = omp_get_wtime();
	for (iY = 0; iY < iYmax; iY++)
	{
		Cy = CyMin + iY * PixelHeight;
		if (fabs(Cy) < PixelHeight / 2) Cy = 0.0;
		for (iX = 0; iX < iXmax; iX++)
		{
			Cx = CxMin + iX * PixelWidth;

			Zx = 0.0;
			Zy = 0.0;
			Zx2 = Zx * Zx;
			Zy2 = Zy * Zy;
			for (Iteration = 0; Iteration < IterationMax && ((Zx2 + Zy2) < ER2); Iteration++)
			{
				Zy = 2 * Zx*Zy + Cy;
				Zx2 = Zx * Zx;
				Zx = Zx2 - Zy2 + Cx;
				Zy2 = Zy * Zy;
			};

			if (Iteration == IterationMax)
			{
				color[iY][iX][0] = 0;
				color[iY][iX][1] = 0;
				color[iY][iX][2] = 0;
			}
			else
			{
				color[iY][iX][0] = 255;
				color[iY][iX][1] = 255;
				color[iY][iX][2] = 255;
			};

		}
	}
	stop = omp_get_wtime();
	czas = stop - start;
	cout << "Czas sekwencyjny = " << czas << endl;

}
void funkcja2()
{
	start = omp_get_wtime();
	#pragma omp parallel private(iY, iX,Cx,Cy,Zx,Zy,Zx2,Zy2,Iteration,tid) shared(color,PixelWidth,PixelHeight)
	{
		tid = omp_get_thread_num();
		#pragma omp for 
		for (iY = 0; iY < iYmax; iY++)
		{
			Cy = CyMin + iY * PixelHeight;
			if (fabs(Cy) < PixelHeight / 2) Cy = 0.0;
			for (iX = 0; iX < iXmax; iX++)
			{
				Cx = CxMin + iX * PixelWidth;

				Zx = 0.0;
				Zy = 0.0;
				Zx2 = Zx * Zx;
				Zy2 = Zy * Zy;
				for (Iteration = 0; Iteration < IterationMax && ((Zx2 + Zy2) < ER2); Iteration++)
				{
					Zy = 2 * Zx*Zy + Cy;
					Zx2 = Zx * Zx;
					Zx = Zx2 - Zy2 + Cx;
					Zy2 = Zy * Zy;
				};

				if (Iteration == IterationMax)
				{
					color[iY][iX][0] = 0;
					color[iY][iX][1] = 0;
					color[iY][iX][2] = 0;
				}
				else 
				{
					color[iY][iX][0] = 50 + tid *15;
					color[iY][iX][1] = 50 + tid *15;
					color[iY][iX][2] = 50 + tid *15;
				}

			}
		}
	}
	stop = omp_get_wtime();
	czas = stop - start;
	cout << "Czas rownolegly = " << czas << endl;

}
int main()
{
	FILE * fp;
	FILE * fp2;
	char filename[] = "sekwencja.ppm";
	char filename2[] = "rownolegle.ppm";
	char comment[] = "# ";
	fp = fopen(filename, "wb");
	fp2 = fopen(filename2, "wb");
	fprintf(fp, "P6\n %s\n %d\n %d\n %d\n", comment, iXmax, iYmax, MaxColorComponentValue);
	fprintf(fp2, "P6\n %s\n %d\n %d\n %d\n", comment, iXmax, iYmax, MaxColorComponentValue);
	funkcja();
	fwrite(color, 1, 3 * iXmax*iYmax, fp);
	fclose(fp);
	funkcja2();
	fwrite(color, 1, 3 * iXmax*iYmax, fp2);
	fclose(fp2);
	return 0;
}
