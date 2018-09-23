#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	scanf("%d", &N);
	int arr[N];
	for(int i = 0; i < N; ++i){
		scanf("%d", arr + i);
	}
	int ans = 0;
	for(int i = 0; i < 32; ++i){
		int k = 0;
		for(int j = 0; j < N; ++j){
			if((arr[j] & (1 << i))){
				k++;
			}
		}
		ans += (1 << i) * (k * (N - k));
		//printf("%d  %d  %d\n", i, ans, k);
	}
	printf("%d\n", ans);
	return 0;
}