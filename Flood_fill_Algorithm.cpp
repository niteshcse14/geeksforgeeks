#include <bits/stdc++.h>
using namespace std;
void flood_fill(vector< vector<int> > &arr, int i, int j, int val, int K, int N, int M, int count)
{
	if(i >= N || j >= M)
	{
		return;
	}
	if(i < 0 || j < 0)
	{
		return;
	}
	if(arr[i][j] == val)
	{
		arr[i][j] = K;                                                   
		//cout << "fun   " << count << "    " << i << "  " << j << "  " << arr[i][j] << "  " << val << "\n";
		flood_fill(arr, i, j - 1, val, K, N, M, count + 1);
		flood_fill(arr, i, j + 1, val, K, N, M , count + 1);
		//flood_fill(arr, i - 1, j - 1, val, K, N, M , count + 1);
		flood_fill(arr, i - 1, j, val, K, N, M, count + 1);
		//flood_fill(arr, i - 1, j + 1, val, K, N, M, count + 1);
		//flood_fill(arr, i + 1, j - 1, val, K, N, M, count + 1);
		flood_fill(arr, i + 1, j, val, K, N, M, count + 1);
		//flood_fill(arr, i + 1, j + 1, val, K, N, M, count + 1);
	}
}
int main()
{
	int T, N, M, x, y, K;
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		vector< vector<int> > arr;
		arr.resize(N, vector<int>(M, 0));
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				cin >> arr[i][j];
			}
		}
		cin >> x >> y >> K;
		int val = arr[x][y];
		/*
		cout << val << "\n";
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				cout << arr[i][j] << "  ";
			}
			printf("\n");
		}
		printf("\n");
	*/
		flood_fill(arr, x, y, val, K, N, M, 0);
		//printf("\n\n");
		
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				cout << arr[i][j] << " ";
			}
			//printf("\n");
		}
		printf("\n");

	}
	return 0;
}
//Flood_fill_Algorithm.cpp