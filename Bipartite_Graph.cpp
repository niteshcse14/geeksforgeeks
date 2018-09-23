#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
#define pb push_back
int t, n, root;
int inp[maxn][maxn], color[maxn];
vector<int> adj[maxn];
bool containsOdd(int src){
    memset(color, -1, sizeof color);
    color[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        //printf("For %d\n", u);
        for (auto i : adj[u]) {
            int v = i;
            //printf("%d ", v);
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u]) {
                //printf("yes %d %d\n", u, v);
                return true;
            }
        }
        //printf("\n");
    }
    return false;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        root = -1;
        scanf ("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &inp[i][j]);
                if (root == -1 && inp[i][j])
                    root = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (inp[i][j]) {
                    adj[i].pb(j);
                }
            }
        }
        //printf("root  %d\n", root);
        if (!containsOdd(root)) printf("1\n");
        else printf("0\n");
        /*
        for (int i = 0; i < n; ++i) 
            printf("%d ", color[i]);
        printf("\n");
        */
    }
    return 0;
}