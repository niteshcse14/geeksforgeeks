#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
char str[maxn];
int cnt,k,t,n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		scanf("%s",str);
		int i=0,j=n-1;
		cnt=0;
		while(i<j){
			if(str[i]==str[j])++i,--j;
			else if(str[i+1]==str[j])cnt++,++i;
			else cnt++,--j;
		}
		if(cnt<=k)printf("1\n");
		else printf("0\n");
	}
	return 0;
}