#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, R;
	cin>>T;
	while(T--)
	{
		cin>>N>>R;
		if(R > N)
		{
			printf("0\n");
		}
		else if(N == R)
		{
			printf("1\n");
		}
		else
		{
			long long int res = 1;
			long long int MOD = 1e9 + 7;
			if(R > (N - R))
			{
				R = N - R;
			}
			int arr[N + 1][R + 1] = { 0 };
			for(int i = 0; i <= N; i++)
			{
				for(int j = 0; j <= min(i, R); j++)
				{
					if(i == j || j == 0)
					{
						arr[i][j] = 1;
					}
					else
					{
						arr[i][j] = arr[i - 1][j - 1] + arr[i -1][j];
						arr[i][j] %= MOD;
					}
				}
			}
			cout<<arr[N][R]<<"\n";
		}
	}
	return 0;
}
//nCr.cpp