#include <bits/stdc++.h>
using namespace std;
void getPattern(int N, int n, bool plus)
{
	if(n == N && plus)
	{
		cout<<N<<"\n";
		return;
	}
	if(N > 0 && plus == false)
	{
		cout<<N<<" ";
		getPattern(N - 5, n, false);
	}
	else
	{
		cout<<N<<" ";
		getPattern(N + 5, n, true);
	}
}
int main()
{
	int T, N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		getPattern(N, N, false);
	}
	return 0;
}
//Print_Pattern.cpp