#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[5001][5001];
int row[8] = {2, 1, -1, -2, -2, -1,  1,  2 };
int cols[8] = {1, 2,  2,  1, -1, -2, -2, -1 };
bool is_safe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < M && arr[x][y] == -1);
}
void print()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
            printf(" %2d ", arr[x][y]);
        printf("\n");
    }
}
bool solve_knight_tour(int x, int y, int moves)
{
	int next_x, next_y, i;
	if(moves == N * M)
	{
		return true;
	}
	for(i = 0; i < 8; i++)
	{
		next_x = x + row[i];
		next_y = y + cols[i];
		if(is_safe(next_x, next_y))
		{
			arr[next_x][next_y] = moves;
			if(solve_knight_tour(next_x, next_y, moves + 1) == true)
			{
				return true;
			}
			else
			{
				arr[next_x][next_y] = -1;
			}
		}
	}
	return false;
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				arr[i][j] = -1;
			}
		}
	    arr[0][0] = 0;
	    if(solve_knight_tour(0, 0, 1) == false)
	    {
	    	printf("Doesn't exist\n");
	    	return false;
	    }
	    else
	    {
	    	print();
	    }
	}
	return 0;
}