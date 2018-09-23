#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MAX = 1e6 + 5;
ll N, T;
ll data;
ll prefix_sum[MAX];
int main()
{
	scanf("%lld", &T);
	while(T--)
	{
		ll sum = 0;
		scanf("%lld", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &data);
			sum += data;
			prefix_sum[i] = sum;
		}
		
	}
	return 0;
}