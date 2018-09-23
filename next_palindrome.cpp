#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string str = "", ans = "";
		str.clear();
		ans.clear();
		int N, data;
		cin>>N;
		for(int i = 0; i < N; i++)
		{
			cin>>data;
			str += to_string(data);
		}
		int count = 0, count_nine = 0;
		for(int i = 0; i < N; i++)
		{
			if(str[i] == '9')
			{
				count_nine++;
			}
		}
		for(int i = 0; i < N / 2; i++)
		{
			if(str[i] == str[N - 1- i])
			{
				count++;
			}
			else
			{
				break;
			}
		}
		//cout<<"count "<<count<<"\n";
		if(count_nine == N)
		{
			printf("1 ");
			for(int i = 0; i < N - 1; i++)
			{
				printf("0 ");
			}
			printf("1\n");
		}
		else if(count == N / 2)
		{
			if(N % 2 == 0)
			{
				str[N / 2] = ((int)str[N / 2] - 48 + 1) + 48;
				str[N / 2 - 1] = ((int)str[N / 2 - 1] - 48 + 1) + 48;
			}
			else
			{
				str[N / 2] = ((int)str[N / 2] - 48 + 1) + 48;
			}
			//cout<<str<<"\n";
			for(int i = 0; i < N; i++)
			{
				cout<<str[i]<<" ";
			}
			cout<<"\n";
		}
		else if(N % 2 != 0)
		{
			string temp = str;
			for(int i = 0; i < N / 2; i++)
			{
				str[N - 1 - i] = str[i];
			}
			if(str < temp)
			{
				if(str[N / 2] == '9')
				{
					str[N / 2] = '0';
					str[N / 2 - 1] = ((int)(str[N / 2 - 1]) - 48 + 1) + 48;
				}
				else
				{
					str[N / 2] = ((int)(str[N / 2]) - 48 + 1) + 48;
				}
			}
			//cout<<str<<"\n";
			for(int i = 0; i < N; i++)
			{
				cout<<str[i]<<" ";
			}
			cout<<"\n";
		}
		else
		{
			for(int i = 0; i < N / 2; i++)
			{
				str[N - 1 - i] = str[i];
			}
			str[N / 2] = ((int)str[N / 2] - 48 + 1) + 48;
			str[N / 2 - 1] = ((int)str[N / 2 - 1] - 48 + 1) + 48;
			//cout<<str<<"\n";
			for(int i = 0; i < N; i++)
			{
				cout<<str[i]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
//next_palindrome.cpp