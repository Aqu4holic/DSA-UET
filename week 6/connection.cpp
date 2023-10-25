#include "bits/stdc++.h"
using namespace std;

int n, m;
struct edge{
	int x = 0, y = 0, z = 0;
	bool marked = 0;

	bool operator < (const edge &o) const{
		return z < o.z;
	}
};
vector <edge> ed;
vector <int> root, sz;

istream &operator >> (istream &in, edge &x){
	return in >> x.x >> x.y >> x.z;
}

ostream &operator << (ostream &ou, edge &x){
	return ou << x.x <<' '<< x.y <<' '<< x.z;
}

int findR(int u){
	for (; u != root[u];){
		u = root[u] = root[root[u]];
	}

	return root[u];
}

bool merge(int u, int v){
	u = findR(u);
	v = findR(v);

	if (u == v){
		return 0;
	}

	if (sz[u] < sz[v]){
		swap(u, v);
	}

	root[v] = u;

	return 1;
}

int main(){
	freopen("connection.txt", "r", stdin);
	freopen("connection.out", "w", stdout);

	cin >> n >> m;
	ed.resize(m + 5);
	root.assign(n + 5, 0);
	sz.assign(n + 5, 1);
	for (int i = 1; i <= m; ++i){
		cin >> ed[i];
	}

	for (int i = 1; i <= n; ++i){
		root[i] = i;
	}

	sort(ed.begin() + 1, ed.begin() + m + 1);

	vector <edge> ans;
	int cnt = n, res = 0;
	for (int i = 1; i <= m && cnt > 1; ++i){
		if (merge(ed[i].x, ed[i].y)){
			ed[i].marked = 1;
			ans.push_back(ed[i]);
			--cnt;
			res += ed[i].z;
		}
	}

	cout << res << '\n';
	for (edge v : ans){
		cout << v << '\n';
	}
}