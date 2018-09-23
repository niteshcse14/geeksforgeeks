#include <bits/stdc++.h>
using namespace std;
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
		int curr_max = 1, max_so_far = 1, mul = 1;
		for(int i = 0; i < N; i++)
		{
			mul = mul * arr[i];
			if(mul == 0)
			{
				mul = arr[i];
			}
			curr_max = max(max(arr[i], arr[i] * curr_max), mul);
			max_so_far = max(curr_max, max_so_far * curr_max);
		}
		cout << max_so_far << "\n";
	}
	return 0;
}