#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll T = 1, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		ll ans = N, n = N;
		while(N % 2 == 0)
		{
			N = N / 2;
		}

		if(N == 1)
		{
			ans = 2;
		}
		else
		{
			ll i = 3;
			while(i <= (ll)sqrt(N))
			{
				if(N % i == 0)
				{
					N = N / i;
					i = 3;
				}
				else
				{
					i += 2;
				}
			}
			if(N > 2)
			{
				ans = N;
			}
			else
			{
				ans = i;
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
//Prime_Factorization_using_Sieve.cpp