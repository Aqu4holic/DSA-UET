// author: blackwhite
// problem: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
#include "bits/stdc++.h"
using namespace std;

struct DSU{
	vector <int> root, Rank;
	int cnt;

	DSU (int x){
		root.assign(x + 5, 0);
		Rank.assign(x + 5, 1);
		cnt = x;
		iota(root.begin(), root.end(), 0);
	}

	int findr(int x){
		return (x == root[x] ? x : root[x] = findr(root[x]));
	}

	int size(int x){
		return(Rank[findr(x)]);
	}

	int unique(){
		return cnt;
	}

	bool same(int x, int y){
		return (findr(x) == findr(y));
	}

	bool merge(int x, int y){
		x = findr(x);
		y = findr(y);

		if (x == y) return 0;

		if (Rank[x] < Rank[y]) swap(x, y);

		Rank[x] += Rank[y];
		root[y] = x;

		--cnt;

		return 1;
	}
};

int main(){
	int n, q;
	cin >> n >> q;
	DSU dsu(n);

	string re = "";
	for (int i = 1, x, y; i <= q; ++i){
		cin >> re >> x >> y;

		if (re == "get"){
			cout << (dsu.same(x, y) ? "YES" : "NO") << '\n';
		}
		else{
			dsu.merge(x, y);
		}
	}
}