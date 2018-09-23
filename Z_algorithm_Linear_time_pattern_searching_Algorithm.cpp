#include <bits/stdc++.h>
using namespace std;
int main(){
	string text, pat;
	cin >> text >> pat;
	string contcat = pat + "$" + text;
	int n = contcat.length();
	int l, r, k;
	l = r = 0;
	int Z[n];
	memset(Z, 0, sizeof(Z));
	for(int i = 1; i < n; ++i){
		if(i < r){
			l = r = i;
			while(r < n && contcat[r - l] == contcat[r]){
				r++;
			}
			Z[i] = r - l;
			r--;
		}
		else{
			k = i - l;
			if(contcat[k] < r - i + 1){
				Z[i] = Z[k];
			}
			else{
				l = i;
				while(r < n && contcat[r - l] == contcat[r]){
					r++;
				}
				Z[i] = r - l;
				r--;
			}
		}
	}
	for(int i = 0; i < n; ++i){
		printf("%d  ", Z[i]);
	}
	printf("\n");
	return 0;
}