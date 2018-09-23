#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
#define V_ll vector<ll>
#define V_int vector<int>
#define	mp make_pair
#define	pb push_back
#define f first
#define s second
#define F front
#define P pop
#define p push
#define Pb pop_back
#define b begin
#define e end
#define M_ll multiset<ll>
#define M_int multiset<int>
#define IT iterator
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mh make_heap
#define ph push_heap
#define Ph pop_heap
#define sh sort_heap
#define ih is_heap
#define FOR_Z(i,a) for(int i=0;i<a;++i)
#define FOR_A(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
#define s_l(a) scanf("%lld",&a)
#define s_ll(a, b) scanf("%lld %lld",&a, &b)
#define s_lll(a, b, c) scanf("%lld %lld %lld",&a, &b, &c)

#define s_i(a) scanf("%d",&a)
#define s_ii(a, b) scanf("%d %d",&a, &b)
#define s_iii(a, b, c) scanf("%d %d %d",&a, &b, &c)

#define p_l(a) printf("%lld\n",a)
#define p_ll(a, b) printf("%lld %lld\n",a, b)
#define p_lll(a, b, c) printf("%lld %lld %lld\n",a, b, c)

#define p_i(a) printf("%d\n",a)
#define p_ii(a, b) printf("%d %d\n",a, b)
#define p_iii(a, b, c) printf("%d %d %d\n",a, b, c)
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
const int MOD = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;
#define INF 0x3f3f3f3f

#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)

ll q_sort (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
//qsort(values, 5, sizeof(int), q_sort);

ll power(ll a, ll b)
{
    int f = 1;
    while(b)
    {
        f = b & 1 ? (f * a) % MOD : f;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return f % MOD;
}

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

ll modpowinverse(ll a) 
{
	return modpow(a, mod - 2);
}
void fastscan(ll &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=gc();
    if(c=='-')
    {
        neg = true;
        c=gc();
    }
    for(;(c>47 && c<58);c=gc())
    x = (x<<1) + (x<<3) +c -48;
    if(neg)
       x *=-1;
}
void fastscan(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=gc();
    if(c=='-')
    {
        neg = true;
        c=gc();
    }
    for(;(c>47 && c<58);c=gc())
    x = (x<<1) + (x<<3) +c -48;
    if(neg)
       x *=-1;
}
//create method to here

class Graph
{
	int V;
	list< pair<int, int> > *adj;
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void number_edges(int src, int dest);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].pb(mp(v, w));
}
void Graph::number_edges(int src, int dest)
{
	int sum = 0;
	set< pair<int, int> > setds;
	V_int dist(V, INF);
	V_int ans(V, 0);
	setds.insert(mp(0, src));
	dist[src] = 0;

	while(!setds.empty())
	{
		pair<int, int> tmp = *(setds.b());
		setds.erase(setds.b());
		int u = tmp.s;
		list< pair<int, int> >::iterator i;
		for(i = adj[u].b(); i != adj[u].e(); i++)
		{
			int v = (*i).f;
			int w = (*i).s;
			if(dist[v] > dist[u] + w)
			{
				if(dist[v] != INF)
				{
					setds.erase(setds.find(mp(dist[v], v)));
				}
				ans[v] = ans[u] + 1;
				dist[v] = dist[u] + w;
				setds.insert(mp(dist[v], v));
			}
		}
	}
    for (int i = 0; i < V; ++i)
    {
     	printf("%d   %d \t\t %d\n",i, ans[i], dist[i]);
    }
}

void solve()
{
	int V, E, u, v, w, a, b;
	fastscan(V);
	fastscan(E);
	Graph g(V);
	FOR_Z(i, E)
	{
		fastscan(u);
		fastscan(v);
		fastscan(w);
		g.addEdge(u - 1, v - 1, w);
	}
	fastscan(a);
	fastscan(b);
	//printf("NUMBER\n");
	g.number_edges(a - 1, b - 1);
}
int main()
{
    fast;
    ll T;
    fastscan(T);
    while(T--)
    {
    	solve();
    }
    return 0;
}
//number_of_edges.cpp