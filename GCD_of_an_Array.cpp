#include <bits/stdc++.h>
using namespace std;
int getGCD(int a, int b)
{
	if(a == 0)
	{
		return b;
	}
	return getGCD(b % a, a);
}
int main()
{
	int T, N;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		int gcd = arr[0];
		for(int i = 1; i < N; i++)
		{
			gcd = getGCD(gcd, arr[i]);
		}
		cout << gcd << "\n";
	}
	return 0;
}