#include <iostream>
using namespace std;

void improved_squre_root(double **a, double *b, const int n);

int main()
{
	int n = 5;
	double **a = NULL, *b = NULL;
	//double temp_a[][3] = { 6,7,5,7,13,8,5,8,6};
	//double temp_b[] = {9,10,9};
	double temp_a[][5] = {
		{2,-2,0,0,-1},
		{-2,3,-2,0,0},
		{0,-2,5,-3,0},
		{0,0,-3,10,4},
		{-1,0,0,4,10} };
	double temp_b[] = {-1,-1,0,11,13};
	b = new double[n];
	a = new double *[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
		b[i] = temp_b[i];
		for (int j = 0; j < n; j++)
			a[i][j] = temp_a[i][j];
	}

	improved_squre_root(a, b, n);
}

void improved_squre_root(double **a, double *b, const int n)
{
	double **l = NULL, *d = NULL;
	l = new double *[n];
	d = new double[n];
	//初始化矩阵
	for (int i = 0; i < n; i++)
	{
		l[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			l[i][j] = 0;
			if (i == j) l[i][j] = 1;
		}
	}

	//进行分解
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i ; j++)
		{
			if (i == j)
			{
				double sum = 0;
				for (int k = 0 ; k < i; k++)
				{
					sum += l[i][k]* l[i][k] * d[k];
				}
				d[i] = a[i][j] - sum;
				cout << d[i] << " ";
			}
			else {
				double sum = 0;
				int min_temp = i > j ? j : i;
				for (int k = 0; k <min_temp; k++)
				{
					sum += l[i][k] * l[j][k] *d[k];
				}
				l[i][j] = (a[i][j]-sum) / d[j];
				cout << l[i][j] << " ";
			}
		}
		cout << endl;
	}

	double *x = new double[n];
	double *y = new double[n];
	//求解y
	for (int i = 0; i< n; i++)
	{
		double sum = 0;
		for (int j = 0 ; j<i ; j++)
		{
			sum += l[i][j] * y[j];
		}
		y[i] = b[i] - sum;
		cout << y[i] << " ";
	}
	cout << endl;

	//求解x
	for (int i = n-1; i > -1; i--)
	{
		double sum = 0;
		for (int j = n-1; j > i  ; j--)
		{
			sum += l[j][i] * x[j];
		}
		x[i] = y[i]/d[i] - sum;
		cout << x[i] << " ";
	}
}