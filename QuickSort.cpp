#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partion(int arr[], int low, int heigh)
{
	int i = low - 1;
	int pivot = arr[heigh];
	for(int j = low; j < heigh; j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1] , &arr[heigh]);
	return (i + 1);
}
void quick_sort(int arr[], int low, int heigh)
{
	if(low <  heigh)
	{
		int pivot = partion(arr, low, heigh);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, heigh);
	}
}
int main()
{
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		quick_sort(arr, 0, N - 1);
		for(int i = 0; i < N; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}