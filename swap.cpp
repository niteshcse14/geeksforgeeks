#include<iostream>
#include<queue>
using namespace std;
int main()
{
	long long int a,b;
	cin>>a>>b;
	a=a^b;
	b=a^b;
	a=a^b;
	cout<<a<<" "<<b<<endl;
	return 0;
}