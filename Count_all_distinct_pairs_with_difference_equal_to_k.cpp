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
		scanf("%d", &N);
		int arr[N];
		set<iPair> s;
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		scanf("%d", &K);
		for(int i = 0; i < N; i++)
		{
			for(int j = i + 1; j < N; j++)
			{
				if(abs(arr[i] - arr[j]) == K)
				{
					s.insert(make_pair(arr[i], arr[j]));
				}
			}
		}
		printf("%d\n", s.size());
	}
	return 0;
}