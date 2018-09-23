#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll dp[2000008];
ll modex(ll x, ll n){
	if(n == 0){
		return 1;
	}
	ll t = modex(x, n / 2);
	if(n % 2 == 0){
		return (t * t) % mod;
	}
	else{
		return (((t * t) % mod) * x) % mod;
	}
}
ll binomial(ll n, ll r){
	ll x = dp[n];
	ll y = dp[r];
	y *= dp[n - r];
	y %= mod;
	y = modex(y, mod - 2);
	x *= y;
	x %= mod;
	return x;
}
int main(){
	dp[0] = 1;
	for(ll i = 1; i < 2000005; ++i){
		dp[i] = dp[i - 1] * i;
		dp[i] %= mod;
	}
	ll n, r, t;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld", &n, &r);
		printf("%lld\n", binomial(n, r));
	}
	return 0;
}