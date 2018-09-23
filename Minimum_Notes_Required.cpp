#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int dp[MAX], arr[MAX];
int main()
{
	int T, N, K;
	int coin[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &K);
		for(int i = 0; i < 9; i++)
		{
			int t = N / coin[i];
			if(t > 0)
			{
				while(t > K)
				{
					t--;
				}
				N -= t * coin[i];
				K -= t;
			}
		}
		printf("%d\n", N);
	}
	return 0;
}