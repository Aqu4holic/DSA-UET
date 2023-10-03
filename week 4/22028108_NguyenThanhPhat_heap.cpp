//author: blackwhite
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define fi first
#define se second
#define pb push_back
#define oo 1e18
#define eps 1e-9
#define el '\n'
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;

inline void io(char *u, string filename){
	int x = u[0] - '0';
	if (x < 0 || x > 9){
		return;
	}
	if (!x){
		freopen((filename + ".inp").c_str(), "r", stdin);
		return;
	}
	if (x == 1){
		freopen((filename + ".inp").c_str(), "r", stdin);
		freopen((filename + ".out").c_str(), "w", stdout);
		return;
	}
	if (x == 2){
		freopen((filename + ".inp").c_str(), "r", stdin);
		freopen((filename + ".ans").c_str(), "w", stdout);
		return;
	}
	freopen((filename + ".out").c_str(), "w", stdout);
}

struct heap{
	int n;
	vector <int> a;

	heap(){
		n = 0;
		a.assign(1e5 + 5, 0);
	}

	void heapify(int id, int n){
		int mx = id;
		int l = 2 * id + 1;
		int r = 2 * id + 2;

		if (l < n && a[l] > a[mx]){
			mx = l;
		}

		if (r < n && a[r] > a[mx]){
			mx = r;
		}

		if (mx != id){
			swap(a[id], a[mx]);

			heapify(id, n);
		}
	}

	void push(int x){
		if (n + 1 > 1e5){
			return;
		}

		a[n++] = x;

		heapify(n - 1, n);
	}

	void pop(){
		a[0] = a[n - 1];
		a[n--] = 0;

		heapify(0, n);
	}

	int top(){
		return a[0];
	}
};

void solve(){
	heap a;

	a.push(10);
	a.push(7);
	a.push(6);
	a.push(19);
	a.push(9);

	cerr << a.top() << el;

	a.pop();

	cerr << a.top() << el;
}

signed main(signed argv, char *args[]){
	cin.tie(0) -> sync_with_stdio(0);
	#ifdef blackwhite
	assert(argv > 1);
	io(args[1], "test");
	#endif

	int tc = 1;
	// cin >> tc;
	for (int tt = 1; tt <= tc; ++tt){
		solve();
	}
}