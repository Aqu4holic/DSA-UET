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

struct Stack{
	struct node{
		node *next = nullptr;
		int val = 0;

		node(){
			val = 0;
			next = nullptr;
		}

		node(int x){
			val = x;
			next = nullptr;
		}

		node(int x, node *nxt){
			val = x;
			next = nxt;
		}

		node(node *root){
			val = root -> val;
			next = root -> next;
		}

		static node *insert(node *root, int x){
			if (!root){
				return root = new node(x);
			}

			node *p = root;
			node *tmp = new node(p);
			p -> val = x;
			p -> next = tmp;

			return root;
		}

		static node *insert(node *root, int pos, int x){
			node *p = root;
			for (int i = 0; i < pos && p; p = p -> next, ++i){
			}

			if (p == nullptr){
				return root = node::insert(root, x);
			}

			node *tmp = new node(p);
			p -> val = x;
			p -> next = tmp;

			return root;
		}

		static node *remove(node *root){
			root = root -> next;

			return root;
		}

		static void print_l(node *root){
			for (node *p = root; p != nullptr; p = p -> next){
				cout << p -> val <<' ';
			}
			cout << el;
		}

		static int get_first(node *root){
			if (root != nullptr){
				return root -> val;
			}

			return 0;
		}
	};

	node *root = nullptr;
	int sz = 0;

	Stack(){
		root = nullptr;
		sz = 0;
	}

	void push(int x){
		++sz;

		root = node::insert(root, x);
	}

	void pop(){
		if (sz){
			root = node::remove(root);
			--sz;
		}
	}

	int top(){
		if (sz){
			return node::get_first(root);
		}

		return 0;
	}

	void print_s(){
		node::print_l(root);
	}

	int size(){
		return sz;
	}

	bool empty(){
		return sz == 0;
	}
};

void solve(){
	int n;
	cin >> n;
	string type;
	Stack s;
	for (int i = 1, x; i <= n; ++i){
		cin >> type;

		if (type == "push"){
			cin >> x;

			s.push(x);
		}
		else{
			s.pop();
		}
	}

	for (; s.size(); s.pop()){
		cout << s.top() <<' ';
	}
	cout << el;
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