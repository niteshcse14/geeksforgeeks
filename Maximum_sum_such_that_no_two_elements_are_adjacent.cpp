#include <bits/stdc++.h>
using namespace  std;
int main()
{
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		int arr[N];
		int inc = 0, exc = 0, new_exc;
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		inc = arr[0];
		for(int i = 1; i < N; i++)
		{
			new_exc = max(inc, exc);
			inc = exc + arr[i];
			exc = new_exc;
		}
		cout << max(inc, exc) << "\n";
	}
	return 0;
}