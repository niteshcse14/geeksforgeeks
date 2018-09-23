#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, count, sum;
	scanf("%d", &T);
	while(T--)
	{
		count = 0;
		scanf("%d %d", &N, &sum);
		int arr[N];
		for(int i = 0;i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + N);
		int l = 0, r = N - 1;
		while(l < r)
		{
			if(arr[l] + arr[r] == sum)
			{
				l++;
				r--;
				count++;
			}
			else if((arr[l] + arr[r]) < sum)
			{
				l++;
			}
			else
			{
				r--;
			}
		}
		printf("%d\n", 2 * count);
	}
	return 0;
}