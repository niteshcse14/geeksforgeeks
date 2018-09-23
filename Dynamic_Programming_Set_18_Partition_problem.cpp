#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int arr[MAX];
bool solve_partition(int N, int sum)
{
	if(sum == 0)
	{
		return true;
	}
	if(N > 0 && sum < 0)
	{
		return false;
	}
	return solve_partition(N - 1, sum - arr[N - 1]) || solve_partition(N - 1, sum);
}
int main()
{
	int N, sum = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	if(sum % 2 != 0)
	{
		printf("false\n");
	}
	else
	{
		printf(solve_partition(N, sum / 2) == 1 ? "true\n" : "false\n");
	}
	return 0;
}