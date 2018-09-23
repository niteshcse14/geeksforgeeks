#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, W;
	cin >> T;
	while(T--)
	{
		cin >> N >> W;
		vector<pair<int, int>> vect;
		int val[N], wt[N];
		for(int i = 0; i < N; i++)
		{
			cin >> val[i];
		}
		for(int i = 0; i < N; i++)
		{
			cin >> wt[i];
		}
		int arr[N + 1][W + 1] = { 0 };
		for(int i = 0; i <= N; i++)
		{
			for(int j = 0; j <= W; j++)
			{
				if(i == 0 || j == 0)
				{
					arr[i][j] = 0;
				}
				else if(wt[i - 1] <= j)
				{
					arr[i][j] = max(val[i - 1] + arr[i - 1][j - wt[i - 1]], arr[i - 1][j]);
				}
				else
				{
					arr[i][j] = arr[i - 1][j];
				}
				//cout << arr[i][j] << "  ";
			}
			//printf("\n");
		}
		cout << arr[N][W] << "\n";
	}
	return 0;
}
//0_1_Knapsack_Problem.cpp