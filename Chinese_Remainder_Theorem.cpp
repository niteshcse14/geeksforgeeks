#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define maxn 1000010
#define ll long long int
ll n, t, M;
ll num[maxn], rem[maxn];
ll mul_inv(ll a, ll m) {
	ll t, y = 0, x = 1, m0 = m, q;
	while (a > 1) {
		q = a / m;
		t = m;
		m = a % m;
		a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0)
		x += m0;
	return x;
}
ll power(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x;
		x = x * x;
		y >>= 1;
	}
	return res;
}
ll chinese() {
	ll prod = 1;
	ll sum = 0;
	for (int i = 0; i < n; ++i)
		prod *= num[i];
	for (int i = 0; i < n; ++i) {
		M = prod / num[i];
		sum = sum + rem[i] * M * mul_inv(M, num[i]);
	}
	return sum % prod;
}
int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &num[i]);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &rem[i]);
		printf("%lld\n", chinese());
	}
	return 0;
}