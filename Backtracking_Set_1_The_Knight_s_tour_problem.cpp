#include <bits/stdc++.h>
using namespace std;
int const MAX = 20;
int arr[20][20];
int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool is_safe(int i, int j, int N)
{
	if(i >= 0 && j >= 0 && j < N && i < N && arr[i][j] == 0)
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
			printf("%2d  ", arr[i][j]);
		}
		printf("\n");
	}
	return;
}
bool knight_tour(int x, int y, int N, int count)
{
	int next_x, next_y;
	if(N * N == count)
	{
		return true;
	}
	for(int i = 0; i < 8; i++)
	{
		next_x = x + xMove[i];
		next_y = y + yMove[i];
		if(is_safe(x + xMove[i], y + yMove[i], N))
		{
			arr[next_x][next_y] = count;
			if(knight_tour(x + xMove[i], y + yMove[i], N, count + 1))
			{
				return true;
			}
			else
			{
				arr[next_x][next_y] = 0;
			}
		}
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
		scanf("%d", &N);
		arr[0][0] = 1;
		if(knight_tour(0, 0, N, 1))
		{
			print_solution(N);
		}
		else
		{
			printf("No Solution\n");
		}
	}
	return 0;
}