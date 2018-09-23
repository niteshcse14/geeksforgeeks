#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, K, X, Y, Q;
	cin >> T;
	while(T--)
	{
		cin >> N >> Q;
		int arr[N];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);
		while(Q--)
		{
			cin >> X >> Y >> K;
			cout << arr[X - 1 + K - 1 - 1] << "\n";
		}
	}
	return 0;
}
//Easy_Query.cpp