#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, start, max_length;
	string str;
	cin >> T;
	while(T--)
	{
		max_length = 1;
		start = 0;
		cin >> str;
		N = str.size();
		bool arr[N][N] = { 0 };
		for(int i = 0; i < N; i++)
		{
			arr[i][i] = true;
		}
		for(int i = 0;i < N - 1; i++)
		{
			if(str[i] == str[i + 1])
			{
				arr[i][i + 1] = true;
				start = i;
				max_length = 2;
				break;
			}
		}
		for(int k = 3; k <= N; k++)
		{
			for(int i = 0; i < N - k + 1; ++i)
			{
				int j = i + k - 1;
				if(arr[i + 1][j - 1] && str[i] == str[j])
				{
					arr[i][j] = true;
					if(k > max_length)
					{
						max_length = k;
						start = i;
					}
				}
			}
		}
		for(int i = start; i < max_length + start; i++)
		{
			cout << str[i];
		}
		cout << "\n";
	}
	return 0;
}
//Longest_Palindromic_Substring.cpp