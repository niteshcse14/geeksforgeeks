#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N;
	cin>>T;
	while(T--)
	{
		int start = clock();
		cin>>N;
		bool arr[N + 1];
		memset(arr, true, N + 1);
		for(int i = 2; i * i <= N; i++)
		{
			if(arr[i] == true)
			{
				for(int j = 2 * i; j <= N; j = i + j)
				{
					arr[j] = false;
				}
			}
		}
		for(int i = 2; i <= N; i++)
		{
		 	if(arr[i])
		 	{
		 		//cout<<i<<" ";
		 	}
		}
		printf("\n");
		int end = clock();
		//cout<<((stop - start) / double(CLOCKS_PER_SEC) * 1000)<<"\n";
		cout<<((end - start)/double(CLOCKS_PER_SEC) * 1000)<<"\n";
	}
	return 0;
}
//Sieve_of_Eratosthenes.cpp