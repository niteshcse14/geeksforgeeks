#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[100005];
	for(int i = 0; i < 100001; i++)
	{
		arr[i] = 0;
	}
	for(int i = 2; i < 100001; i++)
	{
		if(i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
		{
			if(arr[i] == 0)
			{
				for(int j = i; j < 100001; j += i)
				{
					arr[j] = 1;
				}
			}
		}
	}
	int ans[501], j = 1;
	ans[0] = 0;
	for(int i = 2; i < 30; i++)
	{
		if(arr[i] == 1)
		{
			cout << j << "  " << i << "\n";
			ans[j] = i;
			j++;
		}
	}
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		cout << ans[N] << "\n";
	}
	return 0;
}