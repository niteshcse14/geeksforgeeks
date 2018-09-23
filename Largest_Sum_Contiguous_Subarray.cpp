#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, i, j;
	cin >> T;
	while(T--)
	{
		cin >> N;
		int arr[N] = { 0 };
		for(i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		int mx = 0, ans = 0;
		for(int i = 0; i < N; i++)
		{
			mx += arr[i];
			if(ans < mx)
			{
				ans = mx;
			}
			if(mx < 0)
			{
				mx = 0;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
//Largest_Sum_Contiguous_Subarray.cpp