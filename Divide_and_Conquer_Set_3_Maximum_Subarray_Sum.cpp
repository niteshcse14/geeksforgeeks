#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
	return (a > b) ? a : b;
}
int max(int a, int b, int c)
{
	return max(max(a, b), c);
}
int cross_max_sub_array(int arr[], int l, int m, int h)
{
	int sum = 0, left_sum = INT_MIN;
	for(int i = m; i >= l; i--)
	{
		sum += arr[i];
		if(sum > left_sum)
		{
			left_sum = sum;
		}
	}
	sum = 0;
	int right_sum = INT_MIN;
	for(int i = m + 1; i <= h; i++)
	{
		sum += arr[i];
		if(sum > right_sum)
		{
			right_sum = sum;
		}
	}
	return (left_sum + right_sum);
}
int max_sum_array(int arr[], int l, int h)
{
	if(l == h)
	{
		return arr[l];
	}
	int m = (h + l) / 2;
	return max(max_sum_array(arr, l, m), max_sum_array(arr, m + 1, h), cross_max_sub_array(arr, l, m, h));
}
int main()
{
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		cout << max_sum_array(arr, 0, N - 1) << "\n";
	}
	return 0;
}