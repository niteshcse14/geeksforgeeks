#include <bits/stdc++.h>
using namespace std;
string str;
void print_min_max()
{
	vector<int> num;
	vector<char> opr;
	string temp = "";
	int N = str.length();
	for(int i = 0; i < N; i++)
	{
		if(str[i] == '*' || str[i] == '+')
		{
			opr.push_back(str[i]);
			num.push_back(atoi(temp.c_str()));
			temp = "";
		}
		else
		{
			temp += str[i];
		}
	}
	num.push_back(atoi(temp.c_str()));
	int len = num.size();
	int min_dp[len][len];
	int max_dp[len][len];
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len; j++)
		{
			min_dp[i][j] = INT_MAX;
			max_dp[i][j] = INT_MIN;
			if(i == j)
			{
				min_dp[i][j] = max_dp[i][j] = num[i];
			}
		}
	}
	for(int L = 2; L <= len; L++)
	{
		for(int i = 0; i < len - L + 1; i++)
		{
			int j = i + L - 1;
			for(int k = i; k < j; k++)
			{
				int minVal = 0, maxVal = 0;
				if(opr[k] == '+')
				{
					minVal = min_dp[i][k] + min_dp[k + 1][j];
					maxVal = max_dp[i][k] + max_dp[k + 1][j];
				}
				else if(opr[k] == '*')
				{
					minVal = min_dp[i][k] * min_dp[k + 1][j];
					maxVal = max_dp[i][k] * max_dp[k + 1][j];
				}
				if(minVal < min_dp[i][j])
				{
					min_dp[i][j] = minVal;
				}
				if(maxVal > max_dp[i][j])
				{
					max_dp[i][j] = maxVal;
				}
			}
		}
	}
	printf("%d  %d\n", min_dp[0][len - 1], max_dp[0][len - 1]);
}
int main()
{
	cin >> str;
	print_min_max();
	return 0;
}