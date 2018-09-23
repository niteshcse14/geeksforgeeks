#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, sum;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &sum);
		int dp[sum + 1][N + 1];
		for(int i = 0; i <= N; i++)
		{
			dp[0][i] = true;
		}
		for(int i = 1; i <= sum; i++)
		{
			dp[i][0] = false;
		}
		for(int i = 1; i <= sum; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				dp[i][j] = dp[i][j - 1];
				if(i >= arr[j - 1])
				{
					dp[i][j] = dp[i][j] || dp[i - arr[j - 1]][j - 1];
				}
			}
		}
		if(dp[sum][N])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}