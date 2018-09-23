#include <bits/stdc++.h>
using namespace std;
void print(char ans[])
{
	for(int i = 0; i < 3; i++)
	{
		 cout << ans[i];
	}
	printf("\n");
}
void permutation(string str, int count[], char ans[], int N, int temp)
{
	//cout << "AA\n";
	if(temp == N)
	{
		print(ans);
		//return;
	}   
	for(int i = 0; i < N; i++)
	{
		if(count[i] != 0)
		{
			ans[i] = str[i];
			count[i] -= 1;
			permutation(str, count, ans, N, temp); 
		}
		else
		{
			temp++;
		}
	}
}
int main()
{
	int N;
	string str;
	cin >> N >> str;
	char ans[N];
	int count[N];
	for(int i = 0; i < N; i++)
	{
		ans[i] = ' ';
		count[i] = 1;
	}
	permutation(str, count, ans, N, 0);
	return 0;
}