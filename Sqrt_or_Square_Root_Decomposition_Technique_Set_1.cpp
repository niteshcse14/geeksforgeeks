#include <bits/stdc++.h>
using namespace std;
int const MAX = 1e5;
int arr[MAX];
int block[MAX];
int block_size;
int N, block_index, Q, T;
void update(int idx, int val)
{
	int block_number = idx / block_size;
	block[block_number] += val - arr[idx];
	arr[idx] = val;
}
int query(int l, int r)
{
	int sum = 0;
	while((l != 0) && (l < r) && (l % block_size != 0))
	{
		sum += arr[l];
		l++;
	}
	while((l + block_size) <= r)
	{
		sum += block[l / block_size];
		l += block_size;
	}
	while(l <= r)
	{
		sum += arr[l];
		l++;
	}
	return sum;
}
void preprocess()
{
	block_index = -1;
	block_size = sqrt(N);
	for(int i = 0; i < N; i++)
	{
		if(i % block_size == 0)
		{
			block_index++;
		}
		block[block_index] += arr[i];
	}
}
int main()
{
	int l, r, idx, val, type;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		preprocess();
		scanf("%d", &Q);
		while(Q--)
		{
			scanf("%d", &type);
			if(type == 1)
			{
				scanf("%d %d", &idx, &val);
				update(idx, val);
			}
			else if(type == 2)
			{
				scanf("%d %d", &l, &r);
				printf("%d\n", query(l, r));
			}
		}
	}
	return 0;
}