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
	int i = low;
	int pivot = arr[heigh];
	for(int j = low, j < heigh; j++)
	{
		if(arr[j] <= pivot)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[heigh]);
	return i;
}
int kTH_element(int arr[], int low, int heigh, int K)
{
	if(K > 0 && K <= heigh - low + 1)
	{
		int  pos = partion(arr, low, heigh);
		if(pos - low == K -1)
		{
			return arr[pos  ];
		}
	}

}int main()
{
	int N, K;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cin >> K;
	kTH_element(arr, 0, N - 1, K);
	return 0;
}