#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e6 + 5;
int arr[MAX];
vector< pair<int, int> > nums;
vector<int> seg[MAX];
void build_merge_sort_tree(int t, int i, int j)
{
	if(i == j)
	{
		seg[t].push_back(arr[i]);
		return;
	}
	int left = t << 1;
	int right = left | 1;
	int mid = (i + j) / 2;
	build_merge_sort_tree(left, i, mid);
	build_merge_sort_tree(right, mid + 1, j);
	merge(seg[left].begin(), seg[left].end(), seg[right].begin(), seg[right].end(), back_inserter(seg[t]));
}
int query(int t, int i, int j, int l, int r, int k)
{
	if(i == j)
	{
		return seg[t][0];
	}
	int left = t << 1;
	int right = left | 1;
	int mid = (i + j) / 2;
	if(i <= l && j >= r)
	{
		//return upper_bound(seg[t].begin(), seg[t].end(), k) - seg[t].begin();
		return upper_bound(seg[t].begin(), seg[t].end(), k) - seg[t].begin();
	}
	/*
	int total = upper_bound(seg[left].begin(), seg[left].end(), r) - lower_bound(seg[left].begin(), seg[left].end(), l);
	if(total >= k)
	{
		return query(left, i, mid, l, r, k);
	}
	else
	{
		return query(right, mid + 1, j, l, r, k - total);
	}
	*/
	int p1 = query(left, i, mid, l, r, k);
	int p2 = query(right, mid + 1, j, l, r, k);
	return (p1 + p2);
}
int main()
{
	int n, m, x, y, k, idx, ans;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		//nums.push_back(make_pair(arr[i], i));
	}
	//sort(nums.begin(), nums.end());
	build_merge_sort_tree(1, 0, n - 1);
	while(m--)
	{
		scanf("%d %d %d", &x, &y, &k);
		x--;
		y--;
		idx = query(1, 0, n - 1, x, y, k);
		printf("%d\n", idx);
	}
	return 0;
}