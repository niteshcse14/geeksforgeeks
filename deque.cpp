#include <bits/stdc++.h>
using namespace std;
int main()
{
	deque<int> q;
	for(int i=0;i<5;i++)
	{
		q.push_back(i);
	}
	for(int i=5;i<10;i++)
	{
		q.push_front(i);
	}
	deque<int>::iterator itr=q.begin();
	deque<int>::iterator itr1=q.end();
	q.assign(itr,itr1);
	q.erase(itr);
	q.pop_front();
	deque<int>::iterator itr2=q.begin();
	while(itr2!=q.end())
	{
		cout<<*itr2<<"\n";
		itr2++;
	}
}