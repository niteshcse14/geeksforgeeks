#include <bits/stdc++.h>
using namespace std;
int N, T, sum;
int main()
{
	cin >> T;
	while(T--)
	{
		sum = 0;
		cin >> N;
		int arr[N], lis[N];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
			lis[i] = arr[i];
		}
		for(int i = 1; i < N; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(arr[j] < arr[i] && lis[i] < lis[j] + arr[i])
				{
					lis[i] = lis[j] + arr[i];
				}
			}
		}
		int max = 0;
		for(int i = 0; i < N; i++)
		{
			if(max < lis[i])
			{
				max = lis[i];
			}
		}
		cout << max << "\n";
	}
}