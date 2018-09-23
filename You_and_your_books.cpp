#include <bits/stdc++.h>
using namespace std;
int max_Books(int a[], int n, int k)
{
    int sum = 0, ans = 0, count = 0, old_count = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] <= k)
		{
			sum += a[i];
			count++;
			//cout << a[i] << " ";
		}
		else
		{
    		if(sum > ans)
    		{
    		    old_count = count;
    		    ans = sum;
    		    //cout << "    sum   " << ans << "\n";
    		}
    		sum = 0;
    		count = 0;
    		//printf("\n");
		}
	}
	//printf("\n");
	if(old_count < count)
	{
	    old_count = count;
	    ans = max(ans, sum);
	}
	return ans;
}
int main()
{
	int T, N, K;
	cin >> T;
	while(T--)
	{
		cin >> N >> K;
		int arr[N];
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		cout  <<  max_Books(arr, N, K) << "\n";
	}
	return 0;
}
/*
28607
6986 16104    
23620 9806 
23554 22962 
9279 20464 27327 
29832 
8200 
26467 
7958 2581 
12581 
4628 16807 19335 
15811 
14148 3384 
8913 
16315 3686 
1392 
14957 14850 
22061 21185 
2980 
12516 20443 
3299 30412 
6699
*/