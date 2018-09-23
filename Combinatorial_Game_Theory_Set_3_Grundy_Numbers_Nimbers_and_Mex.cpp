#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int MEX(unordered_set<int> Set)
{
	int mex = 0;
	while(Set.find(mex) != Set.end())
	{
		mex++;
	}
	return mex;
}
int grundy(int N)
{
	if(N == 0)
	{
		return 0;
	}
	unordered_set<int> Set;
	for(int i = 0; i < N; i++)
	{
		Set.insert(grundy(i));
	}
	return MEX(Set);
}
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		printf("%d\n", grundy(N));
	}
}