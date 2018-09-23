#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int arr[maxn][maxn];
bool visited[maxn][maxn];
int n, m;
struct points{
	int x;
	int y;
};
points point[maxn];
int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void printPath(int pathIndex){
	for(int i = 0; i < pathIndex; i++){
		printf("(%d, %d) ->  ", point[i].x, point[i].y);
	}
	printf("\n");
}
void dfs(int x, int y, int idx){
	if(x == n - 1 && y == m - 1){
		printPath(idx);
		return;
	}
	for(int i = 0; i < 4; ++i){
		int next_x = x + direction[i][0];
		int next_y = y + direction[i][1];
		if(next_x >= 0 && next_y >= 0 && next_x < n && next_y < m && arr[next_x][next_y] == 0 && visited[next_x][next_y] == false){
			point[idx].x = next_x;
			point[idx].y = next_y;
			visited[next_x][next_y] = true;
			dfs(next_x, next_y, idx + 1);
			visited[next_x][next_y] = false;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &arr[i][j]);
		}
	}
	memset(visited, false, sizeof(visited));
	point[0].x = 0;
	point[0].y = 0;
	dfs(0, 0, 1);
	return 0;
}