#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[] = {1, 2, 5, 66, 90, 67, 8, 9, 65, 577, 999, 1002, 1000214};
	int n, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%d\n", lower_bound(arr, arr + 7, n) - arr);
	}
}