#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
#define V_ll vector<ll>
#define V_int vector<int>
#define	mp make_pair
#define	pb push_back
#define M_ll multiset<ll>
#define M_int multiset<int>
#define IT iterator
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FOR_Z(i,a) for(int i=0;i<a;++i)
#define FOR_A(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
const int MOD = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;
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

struct AdjListNode
{
	struct AdjListNode *next;
	int data;
};
struct AdjList
{
	struct AdjListNode *head;
};
struct Graph
{
	int V;
	struct AdjList *array;
};
struct AdjListNode *newAdjListNode(int dest)
{
	struct AdjListNode *newNode=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->data=dest;
	newNode->next=NULL;

	return newNode;
}
struct Graph *createGraph(int V)
{
	struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->V=V;
	graph->array=(struct AdjList*)malloc(V*sizeof(struct AdjList));
	FOR_Z(i,graph->V)
	{
		graph->array[i].head = NULL;
	}
	return graph;
}
void addEdge(struct Graph *graph, int src, int dest)
{
	struct AdjListNode *newNode=newAdjListNode(dest);
	newNode->next=graph->array[src].head;
	graph->array[src].head=newNode;

	newNode=newAdjListNode(src);
	newNode->next=graph->array[dest].head;
	graph->array[dest].head=newNode;
}
void printGraph(struct Graph *graph)
{
	int v;
	FOR_Z(i,graph->V)
	{
		struct AdjListNode *node = graph->array[i].head;
		while(node)
		{
			printf("%d  ",node->data);
			node=node->next;
		}
		printf("\n");
	}
}
void solve()
{
	int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
}
int main()
{
    fast;
    ll T = sscan();
    while(T--)
    {
    	solve();
    }
    return 0;
}