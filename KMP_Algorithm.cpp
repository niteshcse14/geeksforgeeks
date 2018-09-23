#include <bits/stdc++.h>
using namespace std;
int main()
{
	string patt, text;
	//getline(cin, patt);
	cin >> patt >> text;
	int N = text.size();
	int arr[N] = { 0 };
	arr[0] = 0;
	int i = 1, j = 0;
	while(i < N)
	{
		if(text[i] == text[j])
		{
			arr[i] = j + 1;
			i++;
			j++;
		}
		else if(text[i] != text[j])
		{
			if(j == 0)
			{
				if(text[i] == text[j])
				{
					arr[i] = 1;
					i++;
					j++;
				}
				else
				{
					arr[i] = 0;
					i++;
					j = 0;
				}
			}
			else
			{
				j = arr[j - 1];
			}
		}
	}
	i = 0;
	j = 0;
	while(j < text.size())
	{
		if(patt[i] == text[j])
		{
			i++;
			j++;
		}
		if(i == text.size())
		{
			printf("Found pattern at index %d \n\n", i - j);
			i = arr[i - 1];
		}
		else if(j < text.size() && patt[i] != text[j])
		{
			if(i != 0)
			{
				i = arr[i - 1];
			}
			else
			{
				j++;
			}
		}
	}
	
	return 0;
}
//KMP_Algorithm.cpp