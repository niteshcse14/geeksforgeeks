#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, start_index, maxLen;
	cin >> T;
	while(T--)
	{
		start_index = 0;
		maxLen = 1;
		string str;
		cin >> str;
		int N = str.size();
		int dp[N + 1][N + 1];
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				dp[i][j] = false;
			}
		}
		for(int i = 0; i < N; i++)
		{
			dp[i][i] = true;
		}
		for(int i = 0; i < N - 1; i++)
		{
			if(str[i] == str[i + 1])
			{
				dp[i][i + 1] = true;
				maxLen = 2;
				start_index = i;
			}
		}
		for(int len = 3; len <= N; len++)
		{
			for(int i = 0; i < (N - len + 1); i++)
			{
				int j = i + len - 1;
				if(str[i] == str[j] && dp[i + 1][j - 1] == true)
				{
					start_index = i;
					dp[i][j] = true;
					maxLen = len;
				}
			}
		}
		//printf("%d %d\n", start_index, maxLen);
		for(int i = start_index; i <= maxLen; i++)
		{
			cout << str[i];
		}
		printf("\n");
	}
	return 0;
}