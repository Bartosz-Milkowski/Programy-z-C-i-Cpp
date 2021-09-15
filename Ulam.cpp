#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define N 1000
#define L 61
double start, stop, czas;
unsigned char color[N][N][3];
const int MaxColorComponentValue = 255;
double Pixel = N / L;


void ustaw()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            color[i][j][0] = 255;
            color[i][j][1] = 255;
            color[i][j][2] = 255;
        }
    }
}
int isprime(int n)
{
	int p;
	for (p = 2; p*p <= n; p++)
		if (n%p == 0) return 0;
	return n > 2;
}
int ulam_get_map(int x, int y, int n)
{
    x -= (n - 1) / 2;
    y -= n / 2;

    int mx = abs(x), my = abs(y);
    int l = 2 * max(mx, my);
    int d = y >= x ? l * 3 + x + y : l - x - y;

    return pow(l - 1, 2) + d;
}
void output_ulam_spiral(int n)
{
    int x, y, i, j;

    n -= n % 2 == 0 ? 1 : 0;
	//start = omp_get_wtime();

    for (x = 0; x < n; ++x) {
        for (y = 0; y < n; ++y) {

            int z = ulam_get_map(y, x, n);

                if (isprime(z) || z == 2)
                {
                    for (i = x*Pixel; i < (x*Pixel)+Pixel; ++i)
                    {
                        for (j = y*Pixel; j < (y*Pixel)+Pixel; ++j)
                        {
                            color[i][j][0] = 0;
                            color[i][j][1] = 0;
                            color[i][j][2] = 0;
                        }
                    }
                }

                else
                {
                    for (i = x*Pixel; i < (x*Pixel)+Pixel; ++i)
                    {
                        for (j = y*Pixel; j < (y*Pixel)+Pixel; ++j)
                        {
                            color[i][j][0] = 255;
                            color[i][j][1] = 255;
                            color[i][j][2] = 255;
                        }
                    }
                }
        }
    }
    /*stop = omp_get_wtime();
	czas = stop - start;
	cout << "Czas sekwencyjny = " << czas << endl;*/

}
int main(int c, char **v)
{
    ustaw();
    FILE * fp;
	char filename[] = "ulam.ppm";
	char comment[] = "# ";
	fp = fopen(filename, "wb");
	fprintf(fp, "P6\n %s\n %d\n %d\n %d\n", comment, N, N, MaxColorComponentValue);
    output_ulam_spiral(L);
	fwrite(color, 1, 3 * N*N, fp);
	fclose(fp);
	return 0;
}
