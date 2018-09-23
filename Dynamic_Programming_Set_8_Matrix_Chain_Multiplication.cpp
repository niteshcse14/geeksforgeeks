#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long int
ll arr[MAX];
ll N;
ll matrix_mul(ll i, ll j)
{
	ll dp[N][N];
	for(ll i = 0; i < N; i++)
	{
		dp[i][i] = 0;
	}
	for(ll L = 2; L < N; L++)
	{
		for(ll i = 1; i < (N - L + 1); i++)
		{
			ll j = i + L - 1;
			for(ll k = i; k < j; k++)
			{
				ll cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				if(cost < dp[i][j])
				{
					dp[i][j] = cost;
				}
			}
		}
	}
	return dp[1][N - 1];
}
int main()
{
	scanf("%lld", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
	}
	printf("%lld\n", matrix_mul(1, N - 1));
	return 0;
}