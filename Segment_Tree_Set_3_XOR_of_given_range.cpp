#include <bits/stdc++.h>
using namespace std;
int constructST_Util(int arr[], int ss, int se, int *st, int si)
{
	if(ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}
	int mid = ss + (se - ss) / 2;
	st[si] = constructST_Util(arr, ss, mid, st, 2 * si + 1) + constructST_Util(arr, mid + 1, se, st, 2 * si + 2);
	return st[si];
}
int *constructST(int arr[], int N)
{
	int x = (int)(ceil(log2(N)));
	int max_size = 2 * (int)pow(2, x) - 1;
	int *st = (int *)malloc(sizeof(int) * max_size);
	constructST_Util(arr, 0, N - 1, st, 0);
	return st;
}
int main()
{
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		int *st_arr = constructST(arr, N);
		for(int i = 0; i < 2 * N - 1; i++)
		{
			cout << st_arr[i] << " ";
		}
		printf("\n");
	}
	return 0;
}