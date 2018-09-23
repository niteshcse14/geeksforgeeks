#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, W;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &W);
		int val[N], weight[N];
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &val[i]);
		}
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &weight[i]);
		}
		int dp[N + 1][W + 1];
		for(int i = 0; i <= N; i++)
		{
			for(int j = 0; j <= W; j++)
			{
				if(i == 0 || j == 0)
				{
					dp[i][j] = 0;
				}
				else if(weight[j - 1] <= W)
				{
					dp[i][j] = max(val[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		printf("%d\n", dp[N][W]);
	}
	return 0;
}