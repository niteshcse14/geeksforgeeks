#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		int arr[2 * N] = { 0 };
		int arr1[2 * N] = { 0 };
		for(int i = 0; i < N; i++)
		{
			cin >> arr[N + i];
			arr1[N + i] = arr[N + i];
		}
		int val, MN, MX;
		for(int i = N - 1; i > 0; i--)
		{
			MN = min(arr[i << 1], arr[i << 1 | 1]);
			MX = max(arr1[i << 1], arr1[i << 1 | 1]);
			arr[i] = MN;
			arr1[i] = MX;
		}
		/*
		for(int i = 1; i < 2 * N; i++)
		{
			cout << arr[i] << "  ";
		}
		printf("\n");
		for(int i = 1; i < 2 * N; i++)
		{
			cout << arr1[i] << "  ";
		}
		printf("\n");
		*/
		int Q, l, r, L, R, mx = INT_MIN, mn = INT_MAX;
		Q = 1;
		//cin >> Q;
		while(Q--)
		{
			//cin >> l >> r;
			l = 0;
			r = N;
			mn = INT_MAX;
			for(l += N, r += N; l < r; l >>= 1, r >>= 1)
			{
				if(l & 1)
				{
					if(mn > arr[l])
					{
						mn = arr[l];
					}
					l++;
				}
				if(r & 1)
				{
					int rr = r - 1;
					if(mn > arr[rr])
					{
						mn = arr[rr];
					}
					--r;
				}
			}
			l = 0;
			r = N;
			mx = INT_MIN;
			for(l += N, r += N; l < r; l >>= 1, r >>= 1)
			{
				if(l & 1)
				{
					if(mx < arr1[l])
					{
						mx = arr1[l];
					}
					l++;
				}
				if(r & 1)
				{
					if(mx < arr1[--r])
					{
						mx = arr1[r];
					}
				}
			}
			cout << mx << " " << mn << "\n";
		}
	}
	return 0;
}
//Min_Max_Range_Queries.cpp