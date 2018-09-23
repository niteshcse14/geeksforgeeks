#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, mn = INT_MAX;
	scanf("%d", &N);
	string arr[N], check;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if(mn > arr[i].size())
		{
			check = arr[i];
			mn = arr[i].size();
		}
	}
	string ans = "";
	for(int i = 0; i < mn; i++)
	{
		bool flag = true;
		char ch = check[i];
		for(int j = 0; j < N; j++)
		{
			if(arr[j][i] != ch)
			{
				flag = false;
				break;
			}
		}
		if(!flag)
		{
			cout << ((ans.size() == 0) ? "Empty" : ans) << "\n";
			break;
		}
		else
		{
			ans += ch;
		}
	}
	return 0;
}