#include <bits/stdc++.h>
using namespace std;
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *str, int l, int r)
{
	if(l == r)
	{
		printf("%s\n", str);
	}
	else
	{
		for(int i = l; i <= r; i++)
		{
			swap(str + l, str + i);
			printf("before permute    str = %s,  l  =  %d,  r  =   %d \n", str, l, r);
			permute(str, l + 1, r);
			swap(str + l, str + i);
			printf("after permute     str = %s,  l  =  %d,  r  =   %d \n", str, l, r);
		}
	}
}
int main()
{
	char str[100];// = "ABC";
	scanf("%s", str);
	permute(str, 0, strlen(str) - 1);
	return 0;
}