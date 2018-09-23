#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, N, K;
	cin >> t;
	while(t--)
	{
		cin >> K >> N;
		int arr[N], T[K + 1], INDEX[K + 1];
		for(int i = 1; i < K + 1; i++)
		{
			T[i] = 100;
		}
		for(int i = 0; i < K + 1; i++)
		{
			INDEX[i] = -1;
		}
		T[0] = 0;
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < K + 1; j++)
			{
				if(j >= arr[i])
				{
					if(T[j] > (1 + T[j - arr[i]]))
					{
						INDEX[j] = i;
					}
					T[j] = min(T[j], 1 + T[j - arr[i]]);
				}
			}
		}
		for(int i = 0; i <  K + 1; i++)
		{
			cout << T[i] << "  ";
		}
		printf("\n");
		for(int i = 0; i < K + 1; i++)
		{
			cout << INDEX[i] << "  ";
		}
		printf("\n");
	}
	return 0;
}
//The_Coin_Change_Problem.cpp