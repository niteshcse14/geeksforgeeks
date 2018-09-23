#include<stdio.h>
#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
#define mod 1000000007
using namespace std;

ll modpow(ll a, ll b)
{
	ll r = 1;

	while (b) {
		if (b & 1) {
			r = (r * a) % mod;
		}

		a = (a * a) % mod;

		b >>= 1;
	}

	return r;
}

ll modinv(ll a) 
{
	return modpow(a, mod - 2);
}

inline long long int sscan()
{
   long long int n=0;
   int ch=gc();
   while( ch < '0' || ch > '9' )
        ch=gc();
   while(  ch >= '0' && ch <= '9' )
   {
       n = (n<<3)+(n<<1) + ch-'0';
       ch=gc();
   }
   return n;
}
 
inline void print(long int a)
{                                       /**for print long int**/
	int i=0;
	char S[20];
	while(a>0)
	{
    	S[i++]=a%10+'0';
		a=a/10;
	}
	--i;
	while(i>=0)
		pc(S[i--]);
	pc('\n');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=((60)%mod)*(modinv(11))%mod;
    printf("%lld\n",ans);
    return 0;
}

for(int i = 0; i<= m; i++)
    		{
    			nm=((nm%mod)*(((i+1)%mod)*(c[i][0]*(d+i)+c[i][1])%mod)%mod)%mod;
    			dm=((dm%mod)*((c[i][2]*(d+i)+c[i][3])%mod)%mod)%mod;
    			printf("%d  %lld  %lld  %lld \n",i,d+i,nm,dm);
    		}