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
int getGCD_inRange(int getGCD(int a, int b, int arr[], int N)
{
	int c, d, gcd;
	for(; a < b; a >>= 1, b >>= 1)
	{
		if(a & 1)
		{
			
		}
	}
}
int main()
{
	int T, N, count;
	cin >> T;
	while(T--)
	{
		count = 0;
		cin >> N;
		int arr[2 * N] = { 0 };
		for(int i = 0; i < N; i++)
		{
			cin >> arr[N + i];
		}
		for(int i = N - 1; i > 0; i--)
		{
			arr[i] = arr[i << 1] + arr[i << 1 | 1];
		}
		for(int i = 1; i < 2 * N; i++)
		{
			if(K == arr[i])
			{
				count++;
			}
		}
		cout << count << "\n";
	}
	return 0;
}
//Smallest_Subarray_with_given_GCD.cpp