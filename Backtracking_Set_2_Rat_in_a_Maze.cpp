#include <bits/stdc++.h>
using namespace std;
int const MAX = 1000;
int arr[MAX][MAX];
int ans[MAX][MAX];
bool is_safe(int i, int j, int N)
{
	if(arr[i][j] == 1 && i >= 0 && j >= 0 && i < N && j < N)
	{
		return true;
	}
	return false;
}
void print_solution(int N)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printf("%d  ", ans[i][j]);
		}
		printf("\n");
	}
}
bool rat_maze(int x, int y, int N)
{
	int next_x, next_y;
	if(x == (N - 1) && y == (N - 1))
	{
		ans[x][y] = 1;
		return true;
	}
	if(is_safe(x, y, N))
	{
		ans[x][y] = 1;
		if(rat_maze(x + 1, y, N))
		{
			return true;
		}
		if(rat_maze(x, y + 1, N))
		{
			return true;
		}
		ans[x][y] = 0;
	}
	return false;
}
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		memset(arr, 0, sizeof(arr));
		memset(ans, 0, sizeof(ans));
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		if(arr[0][0] == 0)
		{
			printf("Not Possible\n");
			continue;
		}
		if(rat_maze(0, 0, N))
		{
			print_solution(N);
		}
		else
		{
			printf("Not Possible\n");
		}
	}
	return 0;
}