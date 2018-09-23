#include <bits/stdc++.h>
using namespace std;
int permute(int arr[], int l, int r, int sum)
{
	if(l == r)
	{
		sum += arr[l];
		//printf("%d %d %d %d\n", l, r, arr[l], sum);
		return sum; 
	}
	for(int i = l + 1; i <= r; i++)
	{
		sum = permute(arr, i, r, sum);
		//return sum;
	}
	return sum;
}
int main()
{
	int arr[] = {1, 2, 3, 4, 5}, N = 5;
	for(int i = 0; i < 	N; i++)
	{
		cout << permute(arr, 0, i, 0) << "\n";

	}
	return  0;
}