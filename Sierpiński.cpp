#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <algorithm>

#define N 512

using namespace std;

int level;
unsigned char color[N][N][3];
const int MaxColorComponentValue = 255;


int sierpinski(int x1, int x2, int y1, int y2)
{
    if (level==0)
    {
        return 0;
    }

    level--;

    for (int j = 0; j < x2 - x1; j++)
    {
            color[y2 - 1][x1 + j][0] = 0;
            color[y2 - 1][x1 + j][1] = 0;
            color[y2 - 1][x1 + j][2] = 0;
            color[y1 + j][x1][0] = 0;
            color[y1 + j][x1][1] = 0;
            color[y1 + j][x1][2] = 0;
            color[y1 + j][x1 + j][0] = 0;
            color[y1 + j][x1 + j][1] = 0;
            color[y1 + j][x1 + j][2] = 0;
    }

    sierpinski(x1, (x1 + x2) / 2, y1, (y1 + y2) / 2);
    sierpinski(x1, (x1 + x2) / 2, (y1 + y2) / 2, y2);
    sierpinski((x1 + x2) / 2, x2 , (y1 + y2) / 2, y2);
    level++;
    return level;
}

int main()
{
    cout<<"Podaj poziom: ";
    cin>>level;
    int x1=0,y1=0,x2=N,y2=N;

    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            color[i][j][0]=255;
            color[i][j][1]=255;
            color[i][j][2]=255;
        }

    }
    FILE * fp;
	char filename[] = "sierpinski.ppm";
	char comment[] = "# ";
	fp = fopen(filename, "wb");
	fprintf(fp, "P6\n %s\n %d\n %d\n %d\n", comment, N, N, MaxColorComponentValue);
    sierpinski(x1,x2,y1,y2);
	fwrite(color, 1, 3 * N*N, fp);
	fclose(fp);

    return 0;
}
