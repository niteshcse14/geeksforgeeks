#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
int BIT[MAX];
int ans[MAX];
vector< pair<int, int> > inp;
int N, Q, data, l, r, k;
struct quries
{
	int start;
	int end;
	int val;
};
void update(int ind, int val)
{
	while(ind <= N)
	{
		BIT[ind] += val;
		ind += ind & -ind;
	}
}
int query(int ind)
{
	int sum = 0;
	while(ind > 0)
	{
		sum += BIT[ind];
		ind -= ind & -ind;
	}
	return sum;
}
int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &data);
		inp.push_back(make_pair(data, i));
	}
	sort(inp.begin(), inp.end());
	scanf("%d", &Q);
	quries qre[Q];
	for(int i = 0; i < Q; i++)
	{
		scanf("%d %d %d", &l, &r, &k);
		qre[i].start = l;
		qre[i].end = r;
		qre[i].val = k;
	}
	int curr = 0;
	for(int i = 0; i < Q; i++)
	{
		while(curr < N && inp[curr].first <= qre[i].val)
		{
			update(inp[curr].second + 1, 1);
			curr++;
		}
		ans[i] = query(qre[i].end + 1) - query(qre[i].start);
	}
	for(int i = 0; i < Q; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}