#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// 1st Method
/*
ll lis(ll arr[], ll N, ll *max)
{
	if(N == 1)
	{
		return 1;
	}
	ll res, max_ending_here = 1;
	for(int i = 1; i < N; i++)
	{
		res = lis(arr, i, max);
		if(arr[i - 1] < arr[N - 1] && res + 1 > max_ending_here)
		{
			max_ending_here = res + 1;
		}
	}
	if(max_ending_here > *max)
	{
		*max = max_ending_here;
	}
	return max_ending_here;
}
ll _lis(ll arr[], ll N)
{
	ll max = 1;
	lis(arr, N, &max);
	return max;
}
int main()
{
	ll T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		ll arr[N];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		cout << _lis(arr, N) << "\n";
	}
	return 0;
}
*/

// 2nd Method
int main()
{
	ll T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		ll arr[N];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		int lis[N], ans = 0;
		for(int i = 0; i < N; i++)
		{
			lis[i] = 1;
		}
		for(int i = 1; i < N; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(arr[j] < arr[i] && lis[i] < lis[j] + 1)
				{
					lis[i] = lis[j] + 1;
				}
			}
		}
		for(int i = 0; i < N; i++)
		{
			if(lis[i] > ans)
			{
				ans = lis[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}