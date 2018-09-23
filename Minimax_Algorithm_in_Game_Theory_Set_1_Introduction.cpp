#include <bits/stdc++.h>
using namespace std;
int minmax(int depth, int idx, bool isMax, int arr[], int h)
{
	if(h == depth)
	{
		return arr[idx];
	}
	if(isMax)
	{
		return max(minmax(depth + 1, 2 * idx, false, arr, h), minmax(depth + 1, 2 * idx + 1, false, arr, h));
	}
	else
	{
		return min(minmax(depth + 1, 2 * idx, true, arr, h), minmax(depth + 1, 2 * idx + 1, true, arr, h));
	}
}
int log2(int N)
{
	return (N == 1) ? 0  : 1 + log2(N / 2);
}
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		int arr[N];
		int h = log2(N);
		printf("%d\n", h);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		printf("%d\n", minmax(0, 0, true, arr, h));
	}
	return 0;
}