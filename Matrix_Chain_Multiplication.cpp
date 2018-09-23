#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int n,t;
int inp[maxn],dp[maxn][maxn];
int solve(int st,int en){
	if(st==en)return 0;
	//if(dp[st][en])return dp[st][en];
	int sum=0,mn=INT_MAX;
	for(int i=st;i<en;++i){
		sum=solve(st,i)+solve(i+1,en)+inp[st-1]*inp[i]*inp[en];
		if(sum<mn)mn=sum;
	}
	//dp[st][en]=sum;
	return mn;
}
int _solve(){
	for(int l=2;l<n;++l){
		for(int i=1;i<n-l+1;++i){
			int j=i+l-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<j;++k){
				//printf("%d %d %d\n",i-1,k,j);
				int temp=dp[i][k]+dp[k+1][j]+inp[i-1]*inp[k]*inp[j];
				if(temp<dp[i][j])
					dp[i][j]=temp;
			}
		}
	}
	return dp[1][n-1];
}
int main(){
	scanf("%d",&t);
	while(t--){
	    memset(dp,0,sizeof dp);
	    memset(inp,0,sizeof inp);
	    scanf("%d",&n);
    	for(int i=0;i<n;++i)
    		scanf("%d",&inp[i]);
    	printf("%d\n",_solve());
	}
	return 0;
}