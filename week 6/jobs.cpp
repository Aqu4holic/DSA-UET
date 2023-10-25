#include "bits/stdc++.h"
using namespace std;

int n, m;
vector <vector <int>> a;
vector <int> vis, ans;

void dfs(int u){
	vis[u] = 1;

	for (int v : a[u]){
		if (!vis[v]){
			dfs(v);
		}
	}

	ans.push_back(u);
}

int main(){
	freopen("jobs.txt", "r", stdin);
	freopen("jobs.out", "w", stdout);

	cin >> n >> m;
	a.assign(n + 5, {});
	vis.assign(n + 5, 0);
	for (int i = 1, x, y; i <= m; ++i){
		cin >> x >> y;

		a[x].push_back(y);
	}

	ans.clear();
	for (int i = 1; i <= n; ++i){
		if (!vis[i]){
			dfs(i);
		}
	}

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < n; ++i){
		cout << ans[i] <<' ';
	}
}