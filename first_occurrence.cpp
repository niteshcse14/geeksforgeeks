#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[] = {1, 2, 3, 3, 3, 3, 3, 4, 5, 6};
	int n =  sizeof(arr) / sizeof(int);
	int low = 0, heigh = n - 1,  data = 3, index = -1;
	printf("%d\n", n 	);
	while(low < heigh)
	{
		int mid = (heigh + low) / 2;
		if(arr[mid] == data)
		{
			index = mid;
			heigh = mid - 1;
		}
		else if(arr[mid] < data)
		{
			low = mid + 1;
		}
		else if(arr[mid] > data)
		{
			heigh = mid - 1;
		}
		if(low == heigh || mid == 0)
		{
			break;
		}
		printf("%d  %d  %d\n", low,  heigh, mid);
	}
	printf("%d\n", index);
	return 0;
}