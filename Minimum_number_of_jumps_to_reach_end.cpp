#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		int arr[N];
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		int ans[N + 1];
		ans[0] = 0;
		for(int i = 1; i < N; i++)
		{
			ans[i] = INT_MAX;
			for(int j = 0; j < i; j++)
			{
				if(i <= j + arr[j] && ans[j] != INT_MAX)
				{
					ans[i] = min(ans[i], ans[j] + 1);
					break;
				}
			}
		}
		printf("%d\n", ans[N - 1]);
	}
	return 0;
}