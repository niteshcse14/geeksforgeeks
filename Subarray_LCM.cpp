#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int arr[maxn];
int t, n, cnt, c, sum;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cnt = 0;
		sum = 1;
		c = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			if (sum % arr[i] == 0) {
				cnt = max(cnt, c);
				c = 0;
			}
			else {
				c++;
				sum *= arr[i];
			}
		}
		printf("%d\n", cnt > 1 ? cnt : -1);
	}
	return 0;
}