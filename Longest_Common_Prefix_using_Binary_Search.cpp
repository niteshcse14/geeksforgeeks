#include <bits/stdc++.h>
using namespace std;
bool AllContainPrefix(string arr[], int N, string str, int start, int end)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = start; j <= end; j++)
		{
			if(arr[i][j] != str[j])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int N = 4, MIN = INT_MAX, index;
	cin >> N;
	string prefix = "",arr[N] = { "" };
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if(MIN > arr[i].size())
		{
			MIN = arr[i].size();
			index = i;
		}
	}
	int start, end, mid;
	start = 0;
	end = MIN;
	while(start < end)
	{
		mid = (start + end) / 2;
		if(AllContainPrefix(arr, N, arr[index], start, mid))
		{
			prefix += arr[index].substr(start, mid + 1);
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << prefix << "\n";
	return 0;
}
//Longest_Common_Prefix_using_Binary_Search.cpp