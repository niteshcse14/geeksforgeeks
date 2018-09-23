#include <bits/stc++.h>
using namespace std;
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int arr1[N]. arr2[M]. arr3[N + M];
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for(int i = 0; i < M; i++)
	{
		scanf("%d", &arr2[i]);
	}
	for(int i = 0; i < 2 * N - 1; i++)
	{
		for(int j = 0; j < N; j++)
		{
			arr[i + j] += arr1[i] * arr2[j]
		}
	}
	for(int i = 0; i < 2 * N - 1; i++)
	{
		printf("%d  ", arr3[i]);
	}
	printf("\n");
	return 0;
}