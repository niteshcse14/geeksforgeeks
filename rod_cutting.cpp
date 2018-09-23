#include <bits/stdc++.h>
using namespace std;
int rod_cut(int arr[], int len)
{
	if(len == 0)
	{
		return 0;
	}
	int q = INT_MIN;
	for(int i = 1; i <= len; i++)
	{
		q = max(q, arr[i] + rod_cut(arr, len - i));
	}
	return q;
}
int main()
{
	int T, N, len;
	cin >> T;
	while(T--)
	{
		cin >> N;
		int arr[N + 1];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i + 1];
		}
		cin >> len;
		cout << rod_cut(arr, len) << "\n";
	}
	return 0;
}