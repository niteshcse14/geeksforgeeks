#include <bits/stdc++.h>
using namespace std;
int const MAX = 1000;
int ANS;
int arr[MAX][MAX];
bool is_safe(int i, int j, int N)
{
	if(arr[i][j] == 1 && i >= 0 && j >= 0 && i < N && j < N)
	{
		return true;
	}
	return false;
}
bool rat_maze(int x, int y, int N)
{
	int next_x, next_y;
	if(x == (N - 1) && y == (N - 1))
	{
		ANS++;
	}
	if(is_safe(x, y, N))
	{
		rat_maze(x + 1, y, N);
		rat_maze(x, y + 1, N);
	}
}
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		ANS = 0;
		memset(arr, 0, sizeof(arr));
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		printf("%d\n", ANS);
	}
	return 0;
}