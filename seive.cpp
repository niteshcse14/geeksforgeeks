#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int main()
{
	int prime[MAX];
	for(int i = 0; i < MAX; i++)
	{
		prime[i] = 1;
	}
	for(int i = 2; i < sqrt(MAX); i++)
	{
		if(prime[i])
		{
			for(int j = 2 * i; j < MAX; j += i)
			{
				prime[j] = 0;
			}
		}
	}
	for(int i = 1; i < sqrt(MAX); i++)
	{
		if(prime[i])
		{
			cout << i << " ";
		}
	}
	printf("\n");
	/*
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
	}
	*/
	return 0;
}