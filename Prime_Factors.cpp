#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		int flag = 0;
		while(N % 2 == 0)
		{
			flag = 2;
			N /= 2;
		}
		if(flag == 2)
		{
			cout<<"2 ";
		}
		for(int i = 3; i <= sqrt(N); i = i + 2)
		{
			while(N % i == 0)
			{
				flag = i;
				N /= i;
			}
			if(flag == i)
			{
				cout<<i<<" ";
			}
		}
		if(N > 2)
		{
			cout<<N<<"\n";
		}
		else
		{
			printf("\n");
		}
	}
	return 0;
}
//Prime_Factors.cpp