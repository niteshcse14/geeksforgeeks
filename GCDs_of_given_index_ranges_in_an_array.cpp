#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a, ll b)
{
	if(a == 0)
	{
		return b;
	}
	return gcd(b % a, a);
}
int main()
{
	int T, N, l, r, count, ans;
	cin >> T;
	while(T--)
	{
		count = 0;
		ans = 0;
		cin >> N;
		int arr[2 * N] = { 0 };
		for(int i = 0; i < N; i++)
		{
			cin >> arr[N + i];
		}
		for(int i = N - 1; i > 0; i--)
		{
			arr[i] = gcd(arr[2 * i], arr[2 * i | 1]);
		}
		cin >> l >> r;
		r++;
		for(l += N, r += N; l < r; l /= 2, r /= 2)
		{
			if(l & 1)
			{
				if(count == 0)
				{
					ans = arr[l];
					count++;
				}
				ans = gcd(ans, arr[l++]);
			}
			if(r & 1)
			{
				if(count == 0)
				{
					ans = arr[r - 1];
					count++;
				}
				ans = gcd(ans, arr[--r]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
//GCDs_of_given_index_ranges_in_an_array.cpp