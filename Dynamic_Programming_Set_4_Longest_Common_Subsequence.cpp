#include <bits/stdc++.h>
using namespace std;
int lcs(string X, string Y, int i, int j)
{
	if(i == 0 || j == 0)
	{
		return 0;
	}
	if(X[i] == Y[j])
	{
		return (1 + lcs(X, Y, i - 1, j - 1));
	}
	else
	{
		return max(lcs(X, Y, i - 1, j), lcs(X, Y, i, j - 1));
	}
}
int main()
{
	int T;
	string X, Y;
	cin >> T;
	while(T--)
	{
		cin >> X >> Y;
		cout << 1 + lcs(X, Y, X.size() - 1, Y.size() - 1) << "\n";
	}
	return 0;
}