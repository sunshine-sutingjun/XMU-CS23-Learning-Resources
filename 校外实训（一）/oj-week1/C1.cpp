#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define spacesize 4
#define Eps 1e-6
double inputnum[spacesize + 1];
bool isZero(double x)
{
	return fabs(x) <= Eps;
}
bool count24(double a[], int n)
{
	if (n == 1)
	{
		if (isZero(a[0] - 24))
			return true;
		else
			return false;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double temp[4] = {0};
			int tmp = 0;
			for (int k = 0; k < n; k++)
			{
				if ((k != i) && (k != j))
					temp[tmp++] = a[k];
			}
			temp[tmp] = a[i] + a[j];
			if (count24(temp, n - 1))
				return true;
			temp[tmp] = a[i] - a[j];
			if (count24(temp, n - 1))
				return true;
			temp[tmp] = a[j] - a[i];
			if (count24(temp, n - 1))
				return true;
			temp[tmp] = a[i] * a[j];
			if (count24(temp, n - 1))
				return true;
			if (!isZero(a[j]))
			{
				temp[tmp] = a[i] / a[j];
				if (count24(temp, n - 1))
					return true;
			}
			if (!isZero(a[i]))
			{
				temp[tmp] = a[j] / a[i];
				if (count24(temp, n - 1))
					return true;
			}
		}
	}
	return false;
}
int main()
{
	while (true)
	{
		bool isEndInput = true;
		for (int i = 0; i < spacesize; i++)
		{
			cin >> inputnum[i];
			if (!isZero(inputnum[i]))
				isEndInput = false;
		}
		if (isEndInput)
			break;
		if (count24(inputnum, spacesize))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}