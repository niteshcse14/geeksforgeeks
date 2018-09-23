#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MAX = 10000;
ll arr[MAX] = {0};
ll MOD = 1000000007;
ll fib(int N)
{
	if(N == 0)
	{
		return 0;
	}
	if(N == 1 || N == 2)
	{
		return (arr[N] = 1);
	}
	if(arr[N])
	{
		return arr[N] % MOD;
	}
	ll K = (N & 1) ? (N + 1) / 2 : N / 2;
	arr[N] = (N & 1) ? (fib(K) * fib(K) + fib(K - 1) * fib(K - 1)) :
			(2 * fib(K - 1) + fib(K)) * fib(K);
	return arr[N] % MOD;
}
int main()
{
	ll T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		cout << fib(N) << "\n";
	}
	return 0;
}