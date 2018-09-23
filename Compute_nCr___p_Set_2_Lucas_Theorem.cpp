#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int nCrDP(int N, int R){
	int dp[R + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i <= N; ++i){
		for(int j = min(i, R); j > 0; --j){
			dp[j] = (dp[j] + dp[j - 1]) % MOD;
		}
	}
	return dp[R];
}
int nCrLucas(int N, int R){
	if(R == 0){
		return 1;
	}
	int Ni = N % MOD;
	int Ri = R % MOD;
	return (nCrLucas(N / MOD, R / MOD) * nCrDP(Ni, Ri));
}
int main(){
	int N, R;
	scanf("%d %d", &N, &R);
	printf("%d\n", nCrLucas(N, R));
	return 0;
}