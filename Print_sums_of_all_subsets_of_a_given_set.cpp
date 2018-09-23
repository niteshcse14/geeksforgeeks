#include <bits/stdc++.h>
using namespace std;
void sub_set(int arr[], int l, int r, int sum)
{
	if(l > r)
	{
		cout << sum << " ";
		return;
	}
	sub_set(arr, l + 1, r, sum + arr[l]);
	sub_set(arr, l + 1, r, sum);
	
}
int main()
{
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		int arr[N] = { 0 };
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		//sub_set(arr, 0, N - 1, 0);
		//printf("\n");
		
		int limit = 1 << N;
		int ans[limit];
		int k = 0;
		//cout << "LIMIT " << limit << "\n";
		for(int i = 0; i < limit; i++)
		{
			int sum = 0;
			for(int j = 0; j < N; j++)
			{
				//cout << i << "  " << (1 << j) << "   " << (i & (1 << j)) << "\n";
				if(i & (1 << j))
				{
					sum += arr[j];
				}
			}
			//cout << sum << "  ";
			ans[k] = sum;
			k++;
			//printf("\n");
		}
		sort(ans, ans + k);
		for(int i = 0; i < k; i++)
		{
			cout << ans[i] << " ";
		}
		printf("\n");
	}
	return 0;
}
//Print_sums_of_all_subsets_of_a_given_set.cpp