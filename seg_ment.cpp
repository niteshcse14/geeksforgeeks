#include <bits/stdc++.h>
using namespace std;
void update(int *st, int val, int index)
{
	if(index < 1)
	{
		return;
	}
	st[index] += val;
	update(st, val, (index - 1) / 2);
}
int segment_Build(int *st, int arr[], int ss, int se, int si, int N)
{
	int mid = (ss + se) / 2;
	if(ss == se)
	{
		st[si] = arr[si - N];
		return st[si];
	}
	st[si] = segment_Build(st, arr, ss, mid, 2 * si, N)
			 +
			 segment_Build(st, arr, mid + 1, se, 2 * si + 1, N);
	return st[si];
}
int main()
{
	int T, N, val, index, diff;
	cin >> T;
	while(T--)
	{
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++)
		
{			cin >> arr[i];
		}
		int *st = new int[2 * N];
		segment_Build(st, arr, 0, N - 1, 1, N);	
		for(int i = 1; i < 2 * N; i++)
		{
			printf("%d ", st[i]);
		}
		printf("\n");
		cout << "Enter 'Y' for update something\n";
		char ch;
		cin >> ch;
		if(ch == 'Y')
		{
			cin >> index >> val;
			diff = val - arr[index];
			arr[index] = val;
			update(st, diff, (N + index));
			for(int i = 1; i < 2 * N; i++)
			{
				printf("%d ", st[i]);
			}
			printf("\n");
		}
		int l, r, sum = 0;
		cin >> l >> r;
		l += N;
		r += N + 1;
		for(; l < r; l >>= 1, r >>= 1)
		{
			if(l & 1)
			{
				sum += st[l++];
			}
			if(r & 1)
			{
				sum += st[--r];
			}
		}
		cout << sum << "\n";
	}
	return 0;
}