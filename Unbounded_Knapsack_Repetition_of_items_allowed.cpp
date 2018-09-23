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
			scanf("%d",&val[i]);
		}
		for(int i = 0; i < N; i++)
		{
			scanf("%d",&weight[i]);
		}
		int dp[W + 1];
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= W; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(weight[j] <= i)
				{
					dp[i] = max(dp[i], val[j] + dp[i - weight[j]]);
				}
			}
		}
		printf("%d\n", dp[W]);
	}
	return 0;
}