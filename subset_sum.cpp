#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define pb push_back
int inp[maxn];
int n;
void solve(int idx,vector<int>&ar){
	if(idx<0)return;
	if(idx==0){
		printf("data %d\n",(int)ar.size());
		for(auto i:ar)
			printf("%d ",i);
		printf("\n");
		return;
	}
	for(int i=1;i<=3;++i){
		vector<int>p=ar;
		p.pb(idx);
		solve(idx-i,p);
	}
}
int main(){
	vector<int>ar;
	solve(5,ar);
	return 0;
}
int main(){
	t=1;
	//scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&inp[i]);
		}
	}
	return 0;
}