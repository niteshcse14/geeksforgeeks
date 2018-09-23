#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const long long int MOD = 1e9+7;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,data;
		scanf("%d",&N);
		ll sum = 0;
		
		for(int i = 0; i < N; i++)
		{
			scanf("%d",&data);
			ll ans = (data % MOD) * (i + 1) % MOD * (N - i) % MOD;
			sum += ans % MOD;
		}
		printf("%lld\n",sum % MOD);
	}
}
//Sum_of_Subarrays.cpp