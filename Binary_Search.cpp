#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, T, low, heigh, mid, data, flag;
	cin >> T;
	while(T--)
	{
		cin >> N;
		flag = 0;
		low = 0;
		heigh = N - 1;
		int arr[N] = { 0 };
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		cin >> data;
		while(low <= heigh)
		{
			mid = (low + heigh) / 2;
			if(data == arr[mid])
			{
				flag = 1;
				break;
			}
			if(data > arr[mid])
			{
				low = mid + 1;
			}
			else
			{
				heigh = mid - 1;
			}
		}
		if(flag == 1)
		{
			printf("%d\n", mid);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
//Binary_Search.cpp