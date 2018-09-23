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
#define p_que priority_queue
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

typedef pair<int, int> iPair;
static int sum = 0;
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

struct Tree
{
	struct Tree *left;
	struct Tree *right;
	int data;
};

struct Tree *insert(struct Tree *node, int data)
{
	struct Tree *new_node = (struct Tree*)malloc(sizeof(struct Tree));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	if(node == NULL)
	{
		node = new_node;
	}
	else
	{
		if(node->data < new_node->data)
		{
			node->right = insert(node->right, data);
		}
		else
		{
			node->left = insert(node->left, data);
		}
	}
	return node;
}
bool isLeaf(struct Tree *node)
{
	if(node == NULL)
	{
		return false;
	}
	if(node->left == NULL && node->right == NULL)
	{
		return true;
	}
	return false;
}
void printArray(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("data  %d\n",arr[i]);
	}
	printf("\n");
}
void Root_to_leaf_path_sum_equal_to_a_given_number(struct Tree *node, int len, int arr[])
{
	if(node == NULL)
	{
		return;
	}
	arr[len] = node->data;
	len++;
	if(node->left == NULL && node->right == NULL)
	{
		printArray(arr, len);
	}
	Root_to_leaf_path_sum_equal_to_a_given_number(node->left, len, arr);
	Root_to_leaf_path_sum_equal_to_a_given_number(node->right, len, arr);
}

void solve()
{
	int N;
	fastscan(N);
	struct Tree *tree = NULL;
	tree = insert(tree, 20);
	FOR_A(i , 1, N)
	{
		int data;
		fastscan(data);
		insert(tree, data);
	}
	printf("\n");
	int arr[1000] = {0};
	Root_to_leaf_path_sum_equal_to_a_given_number(tree, 0,arr);
}
int main()
{
    fast;
    ll T = 1;
    //fastscan(T);
    while(T--)
    {
    	solve();
    }
    return 0;
}
//size.cpp
//Root_to_leaf_path_sum_equal_to_a_given_number.cpp