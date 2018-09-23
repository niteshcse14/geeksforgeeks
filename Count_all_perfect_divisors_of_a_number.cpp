#include <bits/stdc++.h>
using namespace std;
#define MAX 17
int arr[MAX];
int main()
{
	for(int i = 1; i * i < MAX; i++)
	{
		for(int j = i * i; j < MAX; j += i * i)
		{
			++arr[j];
		}
	}
	for(int i = 1; i <= MAX; i++)
	{
		cout << i << "  " << arr[i] << " \n ";
	}
	printf("\n");
	return 0;
}
//Count_all_perfect_divisors_of_a_number.cpp