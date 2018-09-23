#include <bits/stdc++.h>
using namespace std;
bool subset_sum(int arr[], int N, int sum)
{
	if(sum == 0)
	{
		return 0;
	}
	if(N == 0 && sum != 0)
	{
		return false;
	}
	if(arr[N - 1] > sum)
	{
		return subset_sum(arr, N - 1, sum);
	}
	return subset_sum(arr, N - 1, sum) || subset_sum(arr, N - 1, sum - arr[N - 1]);
}
int main()
{
	int T, N, sum;
	cin >> T;
	while(T--)
	{
		cin >> N >> sum;
		int arr[N];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		if(subset_sum(arr, N, sum))
		{
		    printf("YES\n");
		}
		else
		{
		    printf("NO\n");
		}
	}
	return 0;
}