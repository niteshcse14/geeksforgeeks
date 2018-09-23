#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int arr1[N], arr2[M], arr3[N + M];
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for(int i = 0; i < M; i++)
	{
		scanf("%d", &arr2[i]);
	}
	for(int i = 0; i < N + M; i++)
	{
		arr3[i] = 0;
	}
	for(int i = 0; i < 2 * N - 1; i++)
	{
		printf("%d\n", i);
		for(int j = 0; j <= i; j++)
		{
			printf("%d %d\n", arr1[j], arr2[i - j]);
			arr3[i] += arr1[j] * arr2[i - j];
		}
		printf("\n\n");
	}
	for(int i = 2 * N - 2; i >= 0; i--)
	{
		printf("%d(X^%d)  ", arr3[i], i);
	}
	printf("\n");
	return 0;
}