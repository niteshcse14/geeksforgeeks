#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		for(int i = 31; i >= 0; i--)
		{
			int x = 1 << i;

			if(x & N)
		 	{
		 		cout << "1";
		 	}
		 	else
		 	{
		 		cout << "0";
		 	}
		}
		printf("\n");
		int64_t ans = (int64_t)pow(2, 31);
		for(int i = 31; i >= 0; i--)
		{
			int64_t x = 1 << i;
			cout << x << "\n";
			if(x & N)
		 	{
		 		//
		 	}
		 	else
		 	{
		 		//cout << i << "\n";
		 		//ans -= x;
		 	}
		}
		cout << ans << "\n";
	}
	return 0;
}
//Count_smaller_values_whose_XOR_with_x_is_greater_than_x.cpp