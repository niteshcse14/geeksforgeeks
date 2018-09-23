#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int main()
{
	int N, data;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &data);
		m[i] = data;
	}
	map<int, int>::iterator itr;
	for(itr = m.begin(); itr != m.end(); itr++)
	{
		cout << (*itr).first << " " <<  (*itr).second << " " <<  m.count(4) << "\n";
	}
	cout << m.count(4) << "\n";
	return 0;
}