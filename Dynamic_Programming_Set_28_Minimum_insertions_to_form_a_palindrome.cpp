#include <bits/stdc++.h>
using namespace std;
int findLCS(string str, string rev)
{
	int N = str.length();
	int M = rev.length();
	int dp[N + 1][M + 1];
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= M; j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if(str[i - 1] == rev[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[N][M];
}
int min_insertion_req(string str)
{
	string a = str;
	reverse(str.begin(), str.end());
	string b = str;
	return (str.length() - findLCS(a, b));
}
int main()
{
	int T;
	string str;
	scanf("%d", &T);
	while(T--)
	{
		cin >> str;
		printf("%d\n", min_insertion_req(str));
	}
	return 0;
}