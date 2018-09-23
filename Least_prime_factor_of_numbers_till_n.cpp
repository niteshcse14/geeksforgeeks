#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		vector<int> vect(N + 1, 0);
		vect[1] = 1;
		for(int i = 2; i <= N; i++)
		{
			if(vect[i] == 0)
			{
				vect[i] = i;
				for(int j = 2 * i; j <= N; j = j + i)
				{
					if(vect[j] == 0)
					{
						vect[j] = i;
					}
				}
			}
		}
		for(int i = 1; i<= N; i++)
		{
			cout<<vect[i]<<" ";
		}
		printf("\n");
	}
	return 0;
}
//Least_prime_factor_of_numbers_till_n.cpp