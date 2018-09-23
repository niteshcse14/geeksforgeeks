#include <bits/stdc++.h>
using namespace std;
int N;
void multiply(int *arr)
{
	int ans[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int sum = 0;
			for(int k = 0; k < N; k++)
			{
				sum += (*((arr + i * N) + k)) * (*((arr + k * N) + j));
			}
			ans[i][j] = sum;
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			*((arr + i * N) + j) = ans[i][j];
		}
	}
}
int main()
{
	double param;
	cin >> param;
	cout << exp(param) << "\n";
	/*
	cin >> N;
	int arr[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	multiply((int *)arr);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout << arr[i][j] << " ";
		}
		printf("\n");
	}
	*/
	return 0;
}