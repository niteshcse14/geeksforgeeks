#include <bits/stdc++.h>
using namespace std;
void printArray(char result[])
{
	for(int i = 0; i < strlen(result); i++)
	{
		cout<<result[i];
	}
	printf("\n");
}
void permute(char str[], int count[], char result[], int level)
{
	if(level == (unsigned)strlen(result))
	{
		printArray(result);
		return;
	}
	for(int i = 0; i < strlen(str); i++)
	{
		if(count[i] == 0)
		{
			continue;
		}
		result[level] = str[i];
		count[i]--;
		permute(str, count, result, level + 1);
		count[i]++;
	}
}

int main()
{
	int T = 1;
	//cin>>T;
	while(T--)
	{
		int level = 0;
		string str;
		cin>>str;
		int count[str.size()] = { 0 };
		char ch[str.size()], result[str.size()];
		for(int i = 0; i < str.size(); i++)
		{
			ch[i] = str[i];
			count[i] = 1;
		}
		permute(ch, count, result, level);
	}
	return 0;
}
//Write_a_program_to_print_all_permutations_of_a_given_string.cpp