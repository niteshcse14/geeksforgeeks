#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, L, R;
	cin >> T;
	while(T--)
	{
		cin >> L >> R;
		cout << (L^R) << "\n";
	}
	return 0;
}