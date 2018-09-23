#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
#define N 4
int arr[N][N];
void updateBIT(int BIT[][N + 1], int x, int y, int val)
{
	for( ; x <= N; x += x & (-x))
	{
		for( ; y <= N; y += y & (-y))
		{
			BIT[x][y] += val;
		}
	}
}
int getSum(int BIT[][N + 1], int x, int y)
{
	int sum = 0;
	for( ; x > 0; x -= x & (-x))
	{
		for( ; y > 0; y -= y & (-y))
		{
			sum += BIT[x][y];// += val;
		}
	}
	return sum;
}
void constructAux(int arr[][N], int aux[][N + 1])
{
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= N; j++)
		{
			aux[i][j] = 0;
		}
	}
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			aux[i][j] = arr[N - j][i - 1];
		}
	}
}
void construct2DBIT(int arr[][N], int BIT[][N + 1])
{
	int aux[N + 1][N + 1];
	constructAux(arr, aux);
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			BIT[i][j] = 0;
		}
	}
	printf("\n");
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			printf("%1d ", aux[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("BIT\n");
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			printf("%1d ", BIT[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			int v1 = getSum(BIT, i, j);
			int v2 = getSum(BIT, i, j - 1);
			int v3 = getSum(BIT, i - 1, j - 1);
			int v4 = getSum(BIT, i - 1, j);
			printf("i = %d j = %d v1 = %d v2 = %d v3 = %d v4 = %d  %d\n", i, j, v1, v2, v3, v4, aux[i][j]);
			updateBIT(BIT, i, j, aux[i][j] - (v1 - v2 - v4 + v3));
			for(int i = 1; i <= N; i++)
			{
				for(int j = 1; j <= N; j++)
				{
					printf("%1d ", BIT[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			printf("%1d ", BIT[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int BIT[N + 1][N + 1];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	construct2DBIT(arr, BIT);
	int x1 = 2, y1 = 2, x2 = 4, y2 = 3;
	int ans = (getSum(BIT, x2, y2) - getSum(BIT, x2, y1 - 1) -
	 getSum(BIT, x1 - 1, y2) + getSum(BIT, x1 - 1, y1 - 1));
	printf("%d\n", ans);
	return 0;
}