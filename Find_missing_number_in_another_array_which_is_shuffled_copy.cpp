#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, sum, data;
	cin >> T;
	while(T--)
	{
		sum = 0;
		cin >> N;
		for(int i = 0 ; i < N; i ++)
		{
			cin >> data;
			sum ^= data;
		}
		for(int i = 0 ; i < N - 1; i ++)
		{
			cin >> data;
			sum ^= data;
		}
		cout << sum << "\n";
	}
	return 0;
}