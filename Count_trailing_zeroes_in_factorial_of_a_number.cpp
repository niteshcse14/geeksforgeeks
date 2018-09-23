#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, count = 0;
	cin>>T;
	while(T--)
	{
		count = 0;
		cin>>N;
		for(int i = 5; (N / i) >= 1; i *= 5)
		{
			count += N / i;
		}
		cout<<count<<"\n";
	}
	return 0;
}
//Count_trailing_zeroes_in_factorial_of_a_number.cpp