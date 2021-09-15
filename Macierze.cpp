
#include <iostream>
#include <ctime>
#include <omp.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int **A, **B, **C, N=1000, i, j, k,**BT;
	double start, stop, wynik;
	A = new int *[N];
	B = new int *[N];
	C = new int *[N];
	BT = new int *[N];
	for (i = 0; i < N; i++)
	{
		A[i] = new int[N];
		B[i] = new int[N];
		C[i] = new int[N];
		BT[i] = new int[N];
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) A[i][j] = (rand() % 50) + 1;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) B[i][j] = (rand() % 50) + 1;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) C[i][j] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			BT[j][i] = B[i][j];
		}
	}

	start = omp_get_wtime();

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	stop = omp_get_wtime();
	wynik = (double)(stop - start);
	cout << "Czas sekwencyjny= " << wynik << endl;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) C[i][j] = 0;

	start = omp_get_wtime();

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
			{
				C[i][j] += A[i][k] * BT[j][k];
			}
		}
	}

	stop = omp_get_wtime();
	wynik = (double)(stop - start);

	cout << "Czas po transpozycji macierzy B= " << wynik << endl;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) C[i][j] = 0;

	start = omp_get_wtime();
	#pragma omp parallel private(i, j, k) shared(A,B,C,N)
	{
		#pragma omp for
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				for (k = 0; k < N; k++)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	}
	stop = omp_get_wtime();
	wynik = (double) (stop - start);
	cout << "Czas rownolegly= " << wynik << endl;

	for (i = 0; i < N; i++)
	{
		delete[] A[i];
		delete[] B[i];
		delete[] BT[i];
		delete[] C[i];
	}

	delete[] A;
	delete[] B;
	delete[] BT;
	delete[] C;

	return 0;
}
