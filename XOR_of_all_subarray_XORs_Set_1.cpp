#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, sum;
	cin >> T;
	while(T--)
	{
		sum = 0;
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		for(int i = 0; i < N; i++)
		{
			if(((i + 1) * (N - i)) & 1)
			{
				sum ^= arr[i];
			}
		}
		cout << sum << "\n";
	}
	return 0;
}