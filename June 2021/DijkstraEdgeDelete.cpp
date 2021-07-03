#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cctype>
#include <cassert>
#include <bitset>
#include <ctime>
 
using namespace std;
 
#define pau system("pause")
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pli pair<ll, int>
#define pil pair<int, ll>
#define clr(a, x) memset(a, x, sizeof(a))
 
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define TREE tree<pli, null_type, greater<pli>, rb_tree_tag, tree_order_statistics_node_update>
TREE T;
*/
 
int n, m, k;
struct E {
	int v, index;
	ll w;
	E () {}
	E (int v, ll w, int index) : v(v), w(w), index(index) {}
};
vector<E> e[300015];
bool ok[300015];
ll dis[300015];
int pre_e[300015], pre_v[300015];


void Dij() {
	priority_queue<pli, vector<pli>, greater<pli> > que;
	clr(dis, 63); dis[1] = 0;
	que.push(pli(0, 1));
	while (que.size()) {
		pli pp = que.top(); que.pop();
		ll td = pp.first;
		int u = pp.second;
		if (td > dis[u]) continue;
		for (int i = 0; i < e[u].size(); ++i) {
			int v = e[u][i].v;
			ll w = e[u][i].w;
			int id = e[u][i].index;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pre_e[v] = id;
				pre_v[v] = u;
				que.push(pli(dis[v], v));
			}
		}
	}
}
int deg[300015];
void build() {
	for (int i = 2; i <= n; ++i) {
		int v = pre_v[i];
		int id = pre_e[i];
		ok[id] = 1;
		++deg[v];
	}
}
void bfs() {
	if (k >= n - 1) {
		k = n - 1;
		return;
	}
	queue<int> que;
	for (int i = 1; i <= n; ++i) {
		if (!deg[i]) que.push(i);
	}
	int te = n - 1;
	while (te > k) {
		int u = que.front(); que.pop();
		int v = pre_v[u];
		int id = pre_e[u];
		--deg[v];
		ok[id] = 0;
		if (!deg[v]) que.push(v);
		--te;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].pb(E(v, w, i));
		e[v].pb(E(u, w, i));
	}
	Dij();
	build();
	bfs();
	printf("%d\n", k);
	for (int i = 1; i <= m; ++i) {
		if (ok[i]) printf("%d ", i);
	}
	return 0;
}
 