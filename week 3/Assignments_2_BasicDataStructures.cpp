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

namespace problem1{
	void solve(){
		int n;
		cin >> n;
		vi a(n);
		for (int &i : a){
			cin >> i;
		}

		sort(all(a));

		int res = 0;
		for (int i = 2, cnt = 1; i <= n; ++i, ++cnt){
			if (a[i] != a[i - 1]){
				res += cnt * (cnt - 1) / 2;
				cnt = 1;
			}
		}

		cout << res << el;
	}
}

namespace problem2{
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

			for (; p -> next != nullptr; p = p -> next){
			}

			p -> next = new node(x);

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

		static node *remove(node *root, int pos){
			node *p = root;
			for (int i = 0; i < pos && p -> next; p = p -> next, ++i){
			}

			if (p -> next == nullptr){
				p = nullptr;
				return root;
			}

			node *tmp = p -> next;
			p -> val = tmp -> val;
			p -> next = tmp -> next;

			return root;
		}

		static void print_l(node *root){
			for (node *p = root; p != nullptr; p = p -> next){
				cout << p -> val <<' ';
			}
			cout << el;
		}
	};

	void solve(){
		int n;
		cin >> n;
		string type;
		node *root = nullptr;
		for (int i = 1, p, x; i <= n; ++i){
			cin >> type >> p;

			if (type[0] == 'i'){
				cin >> x;

				root = node::insert(root, p, x);
			}
			else{
				root = node::remove(root, p);
			}
		}

		node::print_l(root);
	}
}

namespace problem3{
	struct node{
		node *next = nullptr, *prev = nullptr;
		int val = 0;

		node(){
			val = 0;
			next = prev = nullptr;
		}

		node(int x){
			val = x;
			next = prev = nullptr;
		}

		node(int x, node *prv){
			val = x;
			prev = prv;
		}

		node(int x, node *nxt, node *prv){
			val = x;
			next = nxt;
			prev = prv;
		}

		node(node *root){
			val = root -> val;
			next = root -> next;
			prev = root -> prev;
		}

		static node *insert(node *root, int x){
			if (!root){
				return root = new node(x);
			}

			node *p = root;

			for (; p -> next != nullptr; p = p -> next){
			}

			p -> next = new node(x, p);

			return root;
		}

		static void print_l(node *root){
			for (node *p = root; p != nullptr; p = p -> next){
				cerr << p -> val <<' ';
			}
			cerr << el;
		}

		static int count_triplets(node *root, int res = 0){
			for (node *p = root; p != nullptr; p = p -> next){
				if (p -> next && p -> prev){
					res += (p -> val + p -> next -> val + p -> prev -> val) == 0;
				}
			}

			return res;
		}
	};

	void solve(){
		int n;
		cin >> n;
		string type;
		node *root = nullptr;
		for (int i = 1, x; i <= n; ++i){
			cin >> x;

			root = node::insert(root, x);
		}

		cout << node::count_triplets(root);
	}
}

namespace problem4{
	struct Queue{
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

				for (; p -> next != nullptr; p = p -> next){
				}

				p -> next = new node(x);

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

		Queue(){
			root = nullptr;
			sz = 0;
		}

		void enqueue(int x){
			++sz;

			root = node::insert(root, x);
		}

		void dequeue(){
			if (sz){
				root = node::remove(root);
				--sz;
			}
		}

		int front(){
			if (sz){
				return node::get_first(root);
			}

			return 0;
		}

		void print_q(){
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
		Queue q;
		for (int i = 1, x; i <= n; ++i){
			cin >> type;

			if (type[0] == 'e'){
				cin >> x;

				q.enqueue(x);
			}
			else{
				q.dequeue();
			}
		}

		q.print_q();
	}
}

namespace problem5{
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

		s.print_s();
	}
}

namespace problem_bonus{
	struct Queue{
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

				for (; p -> next != nullptr; p = p -> next){
				}

				p -> next = new node(x);

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

		Queue(){
			root = nullptr;
			sz = 0;
		}

		void enqueue(int x){
			++sz;

			root = node::insert(root, x);
		}

		void dequeue(){
			if (sz){
				root = node::remove(root);
				--sz;
			}
		}

		int front(){
			if (sz){
				return node::get_first(root);
			}

			return 0;
		}

		void print_q(){
			node::print_l(root);
		}

		int size(){
			return sz;
		}

		bool empty(){
			return sz == 0;
		}
	};

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

	struct Queue_2stack{
		Stack s1, s2;
		int sz = 0;

		void enqueue(int x){
			++sz;

			for (; s1.size(); s1.pop()){
				s2.push(s1.top());
			}

			s1.push(x);

			for (; s2.size(); s2.pop()){
				s1.push(s2.top());
			}
		}

		void dequeue(){
			if (sz){
				s1.pop();
				--sz;
			}
		}

		int front(){
			if (sz){
				return s1.top();
			}

			return 0;
		}

		int size(){
			return sz;
		}

		bool empty(){
			return sz == 0;
		}
	};

	struct Stack_2queue{
		Queue q1, q2;
		int sz = 0;

		void push(int x){
			++sz;

			q2.enqueue(x);

			for (; q1.size(); q1.dequeue()){
				q2.enqueue(q1.front());
			}

			for (; q2.size(); q2.dequeue()){
				q1.enqueue(q2.front());
			}
		}

		void pop(){
			if (sz){
				q1.dequeue();
				--sz;
			}
		}

		int top(){
			if (sz){
				return q1.front();
			}

			return 0;
		}

		int size(){
			return sz;
		}

		bool empty(){
			return sz == 0;
		}
	};

	void solve_queue_2stack(){
		int n;
		cin >> n;
		string type;
		Queue_2stack q;
		for (int i = 1, x; i <= n; ++i){
			cin >> type;

			if (type[0] == 'e'){
				cin >> x;

				q.enqueue(x);
			}
			else{
				q.dequeue();
			}
		}

		for (; q.size(); q.dequeue()){
			cerr << q.front() <<' ';
		}
		cout << el;
	}

	void solve_stack_2queue(){
		int n;
		cin >> n;
		string type;
		Stack_2queue s;
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
}

void solve(){
	problem_bonus::solve_stack_2queue();
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