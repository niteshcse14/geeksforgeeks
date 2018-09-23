#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int n,t;
int inp[maxn],dp[maxn][maxn];
void solve_print(int i,int j,int *bracket,char &name){
	if(i==j){
		printf("%c",name++);
		return;
	}
	printf("(");
	solve_print(i,*((bracket+i*n)+j),bracket,name);
	solve_print(*((bracket+i*n)+j)+1,j,bracket,name);
	printf(")");
}
void solve(){
	memset(dp,0,sizeof dp);
	int bracket[n][n];
	for(int l=2;l<n;++l){
		for(int i=1;i<n-l+1;++i){
			int j=i+l-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<j;++k){
				int sum=dp[i][k]+dp[k+1][j]+inp[i-1]*inp[k]*inp[j];
				if(sum<dp[i][j]){
					dp[i][j]=sum;
					bracket[i][j]=k;
				}
			}
		}
	}
	//printf("%d\n",dp[1][n-1]);
	char name='A';
	solve_print(1,n-1,(int *)bracket,name);
	printf("\n");
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d",&inp[i]);
		solve();
	}
	return 0;
}