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
#define M_ll multiset<ll>
#define M_int multiset<int>
#define IT iterator
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FOR_Z(i,a) for(int i=0;i<a;++i)
#define FOR_A(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
const int MOD = 1e9+7;
const int N = 1e6+10;
const ll inf_l = 1e18;
const int inf_i = 2147483647;
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)

ll q_sort (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
//qsort(values, 5, sizeof(int), q_sort);

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
class Graph
{
	vector< pii > *adj;
	int V;
	void PrimsUtil(int u, bool visited[]);
public:
	V_int arr, ver;
	Graph(int V);
	void prims();
	void addEdge(int v, int u, int w);
	void display();
	void display_try();
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new vector< pii >[V];
}
void Graph::addEdge(int v, int u, int w)
{
	adj[v].pb(mp(u, w));
	adj[u].pb(mp(v, w));
}
/*
void Graph::display_try()
{
	FOR_Z(i, V)
	{
		cout<<"i "<<i<<"  ";
		FOR_Z(j, adj[i].size())
		{
			cout<<adj[i][j].s<<"  ";
		}
		cout<<"\n\n";
	}
}
*/
void Graph::PrimsUtil(int u, bool visited[])
{
	
	FOR_Z(i,V)
	{
		FOR_Z(j, adj[i].size())
		{
			if(arr[j] > adj[i][j].s)
			{
				visited[j] = true;
				arr.pb(adj[i][j].s);
				ver.pb(adj[i][j].f);
			}
		}
	}
}
void Graph::prims()
{
	bool *visited = new bool[V];
	FOR_Z(i, V)
	{
		visited[i] = false;
	}
	PrimsUtil(0,visited);
}
void Graph::display()
{
	FOR_Z(i, V)
	{
		//cout<<i<<"  "<<ver[i]<<"  "<<arr[i]<<"\n";
	}
}

void solve()
{
	int V = 9, E = 14;
	Graph g(V);
	int a, b, w;//, arr[V] = {inf_i};
	FOR_Z(i, E)
	{
		a = sscan();
		b = sscan();
		w = sscan();
		g.addEdge(a, b, w);
	}
	//g.display_try();
	g.prims();
	g.display();
}
int main()
{
    fast;
    ll T = 1;
    while(T--)
    {
    	solve();
    }
    return 0;
}
//prims_adjancecy.cpp