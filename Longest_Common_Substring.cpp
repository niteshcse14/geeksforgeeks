#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string str, str1;
		int N, M;
		cin >> N >> M >> str >> str1;
		int arr[N + 1][M + 1] = { 0 };
		int MX = INT_MIN;
		for(int i = 0; i <= N; i++)
		{
			for(int j = 0; j <= M; j++)
			{
				arr[i][j] = 0;
			}
		}
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= M; j++)
			{
				if(str[i - 1] == str1[j - 1])
				{
					arr[i][j] = arr[i - 1][j - 1] + 1;
				}
				MX = max(MX, arr[i][j]);
				//cout << str[i - 1] << "  " << str1[j - 1] << "  " << arr[i][j] << "\n";
				//cout << arr[i][j] << "  ";
			}
			//printf("\n");
		}
		cout << MX << "\n";
	}
	return 0;
}
//Longest_Common_Substring.cpp