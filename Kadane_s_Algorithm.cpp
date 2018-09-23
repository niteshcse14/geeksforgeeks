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
		int max_so_far = arr[0], curr_max = arr[0];
		for(int i = 1; i < N; i++)
		{
			curr_max = max(arr[i], curr_max + arr[i]);
			max_so_far = max(max_so_far, curr_max);
		}
		cout << max_so_far << "\n";
	}
	return 0;
}