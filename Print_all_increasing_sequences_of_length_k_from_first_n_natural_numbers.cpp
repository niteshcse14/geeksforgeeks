#include <bits/stdc++.h>
using namespace std;
void printArr(int arr[], int K){
	for(int i = 0; i < K; ++i){
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
void all_increse_seq(int N, int K, int len, int arr[]){
	if(len == K){
		printArr(arr, K);
		return;
	}
	int i = (len == 0) ? 1 : arr[len - 1] + 1;
	len++;
	while(i <= N){
		arr[len - 1] = i;
		all_increse_seq(N, K, len, arr);
		i++;
	}
	len--;
}
int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	int arr[K];
	all_increse_seq(N, K, 0, arr);
	return 0;
}