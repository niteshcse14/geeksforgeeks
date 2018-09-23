#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main()
{
	for(int i = 1; i * i <= 20; i++)
	{
		cout << "i " << i << "\n";
		for(int j = i * i; j <= 20; j += i * i)
		{
			cout << j << "  ";
			arr[j]++;
		}
		printf("\n");
	}
	//int N;
	//cin >> N;
	cout << arr[20] << "\n";
	return 0;
}