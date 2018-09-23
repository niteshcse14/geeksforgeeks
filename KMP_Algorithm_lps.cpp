#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int arr[MAX], len;
string str;
void longest_proper_prefix(int N)
{
	arr[0] = len = 0;
	int i = 1;
	cout << N << "\n";
	//return;
	while(i < N)
	{
		if(str[len] == str[i])
		{
			len++;
			arr[i] = len;
			i++;
		}
		else if(len > 0)
		{
			len = arr[len - 1];
		}
		else
		{
			arr[i] = 0;
			i++;
		}
		//printf("%d ", len);
	}
}
int main()
{
	cin >> str;
	int N = str.size();
	longest_proper_prefix(N);
	for(int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}