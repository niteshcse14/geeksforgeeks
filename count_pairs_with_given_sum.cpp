#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
int main()
{
	int T, N, K, ans;
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		scanf("%d %d", &N, &K);
		int arr[N];
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		for(int i = 0; i < N; i++)
		{
			for(int j = i + 1; j < N; j++)
			{
				if((arr[i] + arr[j]) == K)
				{
					ans++:
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}