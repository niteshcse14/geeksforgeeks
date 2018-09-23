#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll X[2000005], Y[2000005];
void call_sub_array(ll arr[], ll X[], int N, int c)
{
	for(int i = 0; i < (1 << N); i++)
	{
		ll sum = 0;
		for(int j = 0; j < N; j++)
		{
			if(i & (1 << j))
			{
				sum += arr[j + c];
			}
		}
		X[i] = sum;
	}
}

ll solve_subset_sum(ll arr[], ll N, ll sum)
{
	call_sub_array(arr, X, N / 2, 0);
	call_sub_array(arr, Y, N - N / 2, N / 2);
	int size_X = 1 << (N / 2);
	int size_Y = 1 << (N - N / 2);
	sort(Y, Y + size_Y);
	ll max = 0;
	for(int i = 0; i < size_X; i++)
	{
		if(X[i] <= sum)
		{
			int p = lower_bound(Y, Y + size_Y, sum - X[i]) - Y;
			if(p == size_Y || Y[p] != (sum - X[i]))
			{
				p--;
			}
			if((X[i] + Y[p]) > max)
			{
				max = X[i] + Y[p];
			}
		}
	}
	return max;
}
int main()
{
	ll T, N, sum;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld %lld", &N, &sum);
		ll arr[N];
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &arr[i]);
		}
		printf("%lld\n", solve_subset_sum(arr, N, sum));
	}
}