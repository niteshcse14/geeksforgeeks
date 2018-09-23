#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll T, N, R;
	ll arr[52][52];
	for(int i = 0; i < 52; i++)
	{
		arr[0][i] = 1;
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for(int i = 1; i < 52; i++)
	{
		for(int j = i + 1; j < 52; j++)
		{
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
		}
	}
	cin >> T;
	while(T--)
	{
		cin >> N;
		for(int n = 1; n <= N; n++)
		{
			for(int i = 0; i < n; i++)
			{
				cout << arr[i][n - 1] << " ";
			}
			printf("\n");
		}
	}
	return 0;
}
//Pascal_Triangle.cpp