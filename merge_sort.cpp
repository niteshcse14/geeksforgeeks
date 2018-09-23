#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L_arr[n1], R_arr[n2];
	for(i = 0; i < n1; i++)
	{
		L_arr[i] = arr[l + i];
	}
	for(i = 0; i < n2; i++)
	{
		R_arr[i] = arr[m + 1 + i];
	}
	i = j = 0;
	k = l;
	while(i < n1 && j < n2)
	{
		if(L_arr[i] <= R_arr[j])
		{
			arr[k] = L_arr[i++];
		}
		else
		{
			arr[k] = R_arr[j++];
		}
		k++;
	}
	while(i < n1)
	{
		arr[k++] = L_arr[i++];
	}
	while(j < n2)
	{
		arr[k++] = R_arr[j++];
	}
}
void merge_sort(int arr[], int l, int r)
{
	if(l < r)
	{
		int m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
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
		merge_sort(arr, 0, N - 1);
		for(int i = 0; i < N; i++)
		{
			printf("%d  ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}