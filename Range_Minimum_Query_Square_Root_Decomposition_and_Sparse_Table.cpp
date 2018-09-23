#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int arr[MAXN];
int sparse[MAXN][100];
int N;
void sparse_table()
{
	int end = floor(log(N)) + 1;
	for(int i = 0; i < N; i++)
	{
		sparse[i][0] = i;
		printf("%d ", sparse[i][0]);
	}
	printf("\n");
	for(int j = 1; (1 << j) <= N; j++)
	{
		for(int i = 0; (i + (1 << j) - 1) < N; i++)
		{
			if(arr[sparse[i][j - 1]] < arr[sparse[i + (1 << (j - 1))][j - 1]])
			{
				sparse[i][j] = sparse[i][j - 1];
			}
			else
			{
				sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
			}
			printf("%d ", sparse[i][j]);
		}
		printf("\n");
	}
}
int RMQ(int L, int R)
{
	int j = floor(log(R - L + 1));
	if(arr[sparse[L][j]] <= arr[sparse[R - (1 << j) + 1][j]])
	{
		return arr[sparse[L][j]];
	}
	return arr[sparse[R - (1 << j) + 1][j]];
}
int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sparse_table();
	printf("%d\n", RMQ(0, 4));
	printf("%d\n", RMQ(4, 7));
	printf("%d\n", RMQ(7, 8));
	return 0;
}