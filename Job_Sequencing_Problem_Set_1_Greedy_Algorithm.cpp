#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 5;
struct Job {
	int id;
	int deadlinel;
	int profit;
};
Job job[maxn];
int visited[maxn];
int ans[maxn];
int cnt, sum, t, n, p, d, _id;
bool cmp(const Job &a, const Job &b) {
	return a.profit > b.profit;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		cnt = 0;
		sum = 0;
		memset(visited, 0, sizeof(visited));
		memset(ans, 0, sizeof(ans));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &_id, &d, &p);
			job[i].id = _id;
			job[i].deadlinel = d;
			job[i].profit = p;
		}
		sort(job, job + n, cmp);
		for (int i = 0; i < n; ++i) {
			//printf("%d  %d  %d\n", job[i].id, job[i].deadlinel, job[i].profit);
		}
		cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = min(n, job[i].deadlinel) - 1; j >= 0; --j) {
				if(visited[j] == false) {
					visited[j] = true;
					ans[j] = i + 1;
					break;
					//cnt++;
				}
			}
			/*
			if (job[i].deadlinel > cnt) {
				cnt++;
				sum += job[i].profit;
			}
			*/
		}
		sum  = 0;
		cnt = 0;
		for(int i = 0; i < n; ++i) {
			//printf("%d  ", ans[i]);
			if (ans[i] != 0) {
				cnt++;
				sum += job[ans[i] - 1].profit;
			}
		} 
		printf("%d %d\n", cnt, sum);
	}
	return 0;
}