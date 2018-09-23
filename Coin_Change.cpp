#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int arr[MAX];
int dp[MAX];
int K;
int coins(int N, int sum)
{
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < N; i++)
	{
		for(int j = arr[i]; j <= sum; j++)
		{
			dp[j] += dp[j - arr[i]];
		}
	}
	return dp[sum];
}
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &K);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		printf("%d\n", coins(N, K));
	}
	return 0;
}