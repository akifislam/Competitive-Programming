//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-06 13:07:38

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;
char gap = 32;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << gap << p.second << ')';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifdef AKIF
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')' << ':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ll long long
#define lll __int128_t
#define pb push_back
#define mp make_pair
#define All(x) (x).begin(), (x).end()
#define sz(z) (int)((z).size())
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
mt19937 rng((uint_fast32_t)chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;
int no_of_cities, no_of_roads, nodes;

class UnionFind
{
private:
    vector<int> p, rank;

public:
    UnionFind(int N)
    {
        rank.assign(N, 0);
        p.resize(N);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int s)
    {
        return (p[s] == s) ? s : p[s] = findSet(p[s]);
    }
    bool isSameSet(int a, int b)
    {
        return findSet(a) == findSet(b);
    }
    bool unionSet(int a, int b)
    {
        if (!isSameSet(a, b))
        {
            int x = findSet(a);
            int y = findSet(b);

            if (rank[x] > rank[y])
            {
                p[y] = x;
            }
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
            return true;
        }
        else
            return false;
    }
};

vector<vector<int>> graph;
vector<vector<int>> MST;

void Minimum_Spanning_Tree()
{

    sort(All(graph));
    UnionFind *u = new UnionFind(nodes);
    int spanning_tree_edges = 0;

    for (int i = 0; i < graph.size(); i++)
    {
        int from = graph[i][1];
        int to = graph[i][2];
        int w = graph[i][0];

        if (!u->isSameSet(from, to))
        {
            u->unionSet(from, to);
            spanning_tree_edges++;
            MST.pb({w, from, to});
        }
    }
}

int dist[500];

void BFS(int src)
{
    memset(dist, -1, sizeof(dist));
    dist[src] = 0;
    //Node, Weight
    queue<pair<int, int>> Q;
    Q.push({src, 0});

    while (!Q.empty())
    {
        auto x = Q.front();
        Q.pop();
        int u = x.first; //Value
        int w = x.second;

        for (int i = 0; i < graph[u].size(); i++)
        {
            if (dist[i] == -1)
            {
                Q.push({graph[u][i], w});
                cout << graph[u][i] << endl;
            }
        }
    }
}

void solve()
{
    cin >> no_of_cities >> no_of_roads;

    nodes = no_of_cities;
    graph.resize(nodes);
    graph.clear();

    int from, to, w;

    for (int i = 0; i < no_of_roads; i++)
    {
        cin >> from >> to >> w;
        graph.pb({w, from, to});
    }
    int my_city;
    cin >> my_city;

    Minimum_Spanning_Tree();
    BFS(my_city);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}