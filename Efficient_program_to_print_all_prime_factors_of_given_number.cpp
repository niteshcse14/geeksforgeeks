#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1, N;
	//cin >> T;
	while(T--)
	{
		cin >> N;
		while(N % 2 == 0)
		{
			N /= 2;
			printf("2 ");
		}
		for(int i = 3; i <= sqrt(N); i += 2)
		{
			while(N % i == 0)
			{
				printf("%d ", i);
				N /= i;
			}
		}
		if(N > 2)
		{
			printf("%d", N);
		}
		printf("\n");
	}
	return 0;
}