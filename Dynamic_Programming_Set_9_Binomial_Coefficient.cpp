#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll MOD = 1000000007;
int main()
{
	int T, N, R;
	//ll arr[100][100];
	vector< vector<ll> > arr(1001, vector<ll>(1001));
	for(int i = 0; i <= 1000; i++)
	{
		for(int j = i; j <= 1000; j++)
		{
			if(i == 0 || i == j)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i][j - 1];
				arr[i][j] = arr[i][j] % MOD;
			}
		}
	}
	/*
	for(int i = 0; i <= 5; i++)
	{
		for(int j = 0; j <= 5; j++)
		{
			cout << arr[i][j] << " ";
		}
		printf("\n");
	}
	*/
	cin >> T;
	while(T--)
	{
		cin >> N >> R;
		if(N >= R)
		{
			cout << arr[R][N] % MOD << "\n";
		}
		else
		{
			cout << "0\n";
		}
	}
	return 0;
}