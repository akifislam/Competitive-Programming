//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-06-15 11:19:21

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

int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};

const int SIZE = 3e5 + 10;
int n, m, w, k;

vector<pair<int, pair<int, int>>> graph[SIZE];
int dist[SIZE];
vector<int> par(n+1,-1);
bool processed[SIZE];

void Dijkstra(int x)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[x] = 0;

    priority_queue<pair<int, int>> Q;
    Q.push({0, x});

    while (!Q.empty())
    {
        int a = Q.top().second; // Node Value

        Q.pop();

        if (processed[a])
            continue;
        processed[a] = true;

        for (auto u : graph[a])
        {
            int b = u.first;             //Node
            int w = u.second.first;      //Weight;
            int index = u.second.second; //Index

            if (dist[b] > dist[a] + w)
            {
                dist[b] = dist[a] + w;
                Q.push({-dist[b], b});
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> k;

    int from, to;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> w;
        graph[from].pb({to, {w, i + 1}});
        graph[to].pb({from, {w, i + 1}});
    }
    Dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}