#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll T, N, R;
	ll arr[1002][1002];
	for(int i = 0; i < 1002; i++)
	{
		arr[0][i] = 1;
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for(int i = 1; i < 1002; i++)
	{
		for(int j = i + 1; j < 1002; j++)
		{
			arr[i][j] = arr[i][j - 1] % 1000000007  + arr[i - 1][j - 1] % 1000000007;
			arr[i][j] %= 1000000007;
		}
	}
	cin >> T;
	while(T--)
	{
		cin >> N >> R;
		cout << arr[R][N] << "\n";
	}
	return 0;
}
//compute_n_C_r.cpp