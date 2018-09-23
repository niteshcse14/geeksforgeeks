#include <bits/stdc++.h>
using namespace std;
int arr[26];
int main(){
	int t;
	char str[100000];
	scanf("%d", &t);
	while(t--){
		scanf("%s", str);
		memset(arr, 0, sizeof(arr));
		int n = strlen(str);
		for(int i = 0; i < n; ++i){
			arr[str[i] - 'a']++;
		}
		int sum = 0;
		for(int i = 0; i < 26; ++i){
			sum += (arr[i] > 0) ? (int)pow(2, arr[i] - 1): 0;
		}
		printf("%d\n", sum);
	}
	return 0;
}          