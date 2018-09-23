#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int arr[MAX];
int main()
{
	arr[1] = 1;
	for(int i = 2; i < MAX; i++)
	{
		if(arr[i] == 0)
		{
			arr[i] = i;
			for(int j = 2 * i; j < MAX; j += i)
			{
				if(arr[j] == 0)
				{
					arr[j] = i;
				}
			}
		}
	}
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		for(int i = 1; i <= N; i++)
		{
			cout << arr[i] << " ";
		}
		printf("\n");
	}
	return 0;
}
//Least_Prime_Factor.cpp