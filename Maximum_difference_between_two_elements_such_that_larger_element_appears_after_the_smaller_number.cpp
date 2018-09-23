#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, max_diff, min_element;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		max_diff = arr[1] - arr[0];
		min_element = arr[0];
		for(int i = 1; i < N; i++)
		{
			if(arr[i] - min_element > max_diff)
			{
				max_diff = arr[i] - min_element;
			}
			if(min_element > arr[i])
			{
				min_element = arr[i];
			}
		}
		printf("%d\n", max_diff);
	}
	return 0;
}