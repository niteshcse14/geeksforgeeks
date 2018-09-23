#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void sieveOfEratosthenese(ll N, ll a[], bool arr[])
{
	for(ll i = 2; i <= N; i++)
	{
		arr[i] = true;
	}
	arr[1] = false;
	for(ll i = 2; i * i <= N; i++)
	{
		if(arr[i])
		{
			for(ll j = 2 * i; j <= N; j += i)
			{
				arr[j] = false;
			}
		}
	}
	ll j = 0;
	for(ll i = 2; i <= N; i++)
	{
		if(arr[i])
		{
			a[j] = i;
			j++;
		}
	}
}
int main()
{
	ll N, ans = 1;
	cin >> N;
	ll a[N + 1];
	bool arr[N + 1];
	sieveOfEratosthenese(N, a, arr);
	for(ll i = 0;; i++)
	{
		if(a[i] * a[i] * a[i] > N)
		{
			break;
		}
		ll count = 1;
		while(N % a[i] == 0)
		{
			N = N / a[i];
			count++;
		}
		ans = ans * count;
	}
	if(arr[N])
	{
		ans = ans * 2;
	}
	else if(arr[(ll)sqrt(N)])
	{
		ans = ans * 3;
	}
	else if(N != 1)
	{
		ans = ans * 4;
	}
	cout << ans << "\n";
	return 0;
}