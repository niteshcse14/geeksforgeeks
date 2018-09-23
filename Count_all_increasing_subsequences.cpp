#include <bits/stdc++.h>
using namespace std;
int const MAX = 100000;
int arr[MAX];
int dp[MAX];
int main()
{
	int T, N ;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
			dp[i] = 1;
		}
		if(N > 1 &&  arr[1] > arr[0])
		{
			dp[1] = 2;
		}
		//memset(dp, 1, sizeof(dp));
		for(int i = 0; i < N; i++)
		{
			printf("%d  ", dp[i]);
		}
		printf("\n");
		for(int i = 2; i < N; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(arr[i] > arr[j] && (1 + dp[j]) > dp[i])
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
		for(int i = 0; i < N; i++)
		{
			printf("%d  ", dp[i]);
		}
		printf("\n");
		int sum = 0;
		for(int i = 0; i < N; i++)
		{
			sum += dp[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}