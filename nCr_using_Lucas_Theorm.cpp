#include <bits/stdc++.h>
using namespace std;
int nCr(int N, int R, int P)
{
	int C[R + 1];
	memset(C, 0, sizeof(C));
	C[0] = 1;
	for(int i = 1; i<= N; i++)
	{
		for(int j = min(i, R); j > 0; j--)
		{
			C[j] = (C[j] + C[j - 1]) % P;
		}
	}
	return C[R];
}
int lucas(int N, int R, int P)
{
	if(R == 0)
	{
		return 1;
	}
	return lucas(N / P, R / P, P) * nCr(N % P, R % P, P) % P;
}
int main()
{
	int T, N, R, P;
	cin >> T;
	while(T--)
	{
		cin >> N >> R >> P;
		cout << lucas(N, R, P) << "\n";
	}
}
//nCr_using_Lucas_Theorm.cpp