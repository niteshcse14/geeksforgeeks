#include <bits/stdc++.h>
using namespace std;
int CeilIndex(vector<int> &arr, int l, int r, int key)
{
	while(r - l > 1)
	{
		int m = l + (r - l) / 2;
		if(arr[m] >= key)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	return r;
}
int main()
{
	int T, N, len;
	cin >> T;
	while(T--)
	{
		cin >> N;
		int arr[N] = { 0 };
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		len = 1;
		vector<int> tail(N, 0);
		for(int i = 1; i < N; i++)
		{
			if(arr[i] < tail[0])
			{
				tail[0] = arr[i];
			}
			else if(arr[i] > tail[len - 1])
			{
				tail[len++] = arr[i];
			}
			else
			{
				tail[CeilIndex(tail, -1, len - 1, arr[i])] = arr[i];
			}
		}
	}
	cout << len << "\n";
	return 0;
}
//Longest_Increasing_Subsequence_Size_N_og_N.cpp