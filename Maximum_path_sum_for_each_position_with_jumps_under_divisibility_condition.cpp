#include <bits/stdc++.h>
using namespace std;
int const MAX = 1e5 + 5;
int arr[MAX];
int dp[MAX + 1];
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		for(int i = 0; i < N; i++)
		{
			dp[i] = arr[i];
			int maxi = 0;
			for(int j = 1; j <= sqrt(i + 1); j++)
			{
				if((i + 1) % j == 0 && (i + 1) != j)
				{
					printf("%d    %d  %d  %d\n", i, dp[j - 1], dp[j], dp[(i + 1) / j - 1]);
					if(dp[j - 1] > maxi)
					{
						maxi = dp[j - 1];
					}
					if(dp[(i + 1) / j - 1] > maxi && j != 1)
					{
						maxi = dp[(i + 1) / j - 1];
					}
				}
			}
			dp[i] += maxi;
			printf("dp  %d\n\n", dp[i]);
		}
		for(int i = 0; i < N; i++)
		{
			printf("%d  ", dp[i]);
		}
		printf("\n");
	}
	return 0;
}