#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	int arr[100000];
	arr[0] = 1;
	for(int i = 1; i < 10; i++)
	{
		arr[i] = 2 * arr[i - 1] + 1;
		cout << arr[i] << "\n";
	}
	return 0;
}