#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int count = 0;
		string str;
		cin>>str;
		for(int i = 0; i < str.size() / 2; i++)
		{
			if(str[i] == str[str.size() -1 - i])
			{
				count++;
			}
		}
		if(count == (str.size() / 2))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}
//Check_if_a_number_is_Palindrome.cpp