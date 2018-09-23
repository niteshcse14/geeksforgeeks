#include <bits/stdc++.h>
using namespace std;
void replace(vector< vector<char> > &ch, int i, int j, int N, int M)
{
	if(i < 0 || j < 0)
	{
		return;
	}
	if(i >= N || j >= M)
	{
		return;
	}
	if(ch[i][j] == 'O')
	{
		ch[i][j] = '-';
		replace(ch,  i, j - 1 , N, M);
		replace(ch,  i, j + 1 , N, M);
		replace(ch,  i - 1, j , N, M);
		replace(ch,  i + 1, j , N, M);
	}
}
int main()
{
	int N, M, T;
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		vector< vector<char> > arr;
		arr.resize(N, vector<char>(M));
		for(int i = 0; i < N; i++)
		{
			for(int j = 0 ; j < M; j++)
			{
				cin >> arr[i][j];
			}
		}
		for(int i = 0; i < N; i++)
		{
			if(arr[i][0] == 'O')
			{
				replace(arr, i, 0, N, M);
			}
		}
		for(int i = 0; i < N; i++)
		{
			if(arr[i][M - 1] == 'O')
			{
				replace(arr, i, M - 1, N, M);
			}
		}
		for(int i = 0; i < M; i++)
		{
			if(arr[0][i] == 'O')
			{
				replace(arr, 0, i, N, M);
			}
		}
		for(int i = 0; i < M; i++)
		{
			if(arr[N - 1][i] == 'O')
			{
				replace(arr, N - 1, i, N, M);
			}
		}
		for(int i = 0; i < N; i++)
		{
			for(int j = 0 ; j < M; j++)
			{
				if(arr[i][j] == '-')
				{
					arr[i][j] = 'O';
				}
				else if(arr[i][j] == 'O')
				{
					arr[i][j] = 'X';
				}
				cout << arr[i][j] << " ";
			}
			//printf("\n");
		}
		printf("\n");
	}
	return 0;
}
//Replace_O_s_with_X_s.cpp