#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
int bits[32], inp[maxn];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &inp[i]);
		for (int i = 0; i < n; ++i) {
			//
		}
	}
	return 0;
}
/*
3, 3, 2, 3, 4, 4, 4, 5, 5, 5

#1	bit array

2	010
3	011
4	100
5	101

1 2 3
6 4 6
working.....!!
Running Complexity : O(BITS*n)
Space Complexity : expected O(1)

#2	Bitmasking

#3	Mathematical

*/