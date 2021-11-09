//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-06 11:41:42

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
ll no_of_houses, nodes;
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

vector<pair<ll, pair<ll, ll>>> graph;

ll MST()
{
    ll cost = 0;
    sort(All(graph));

    UnionFind *u = new UnionFind(nodes);
    for (int i = 0; i < graph.size(); i++)
    {
        int w = graph[i].first;
        int from = graph[i].second.first;
        int to = graph[i].second.second;

        // cout << "Checking Weight : " << w << endl;

        if (!u->isSameSet(from, to))
        {
            cost += w;
            u->unionSet(from, to);
        }
    }
    // cout << "Min Cost : " << cost << endl;
    return cost;
}

ll MaxST()
{
    // sort(All(graph),greater<>());
    ll cost = 0;

    UnionFind *ut = new UnionFind(nodes);
    for (int i = graph.size() - 1; i >= 0; i--)
    {
        int w = graph[i].first;
        int from = graph[i].second.first;
        int to = graph[i].second.second;

        // cout << "Checking Weight : " << w << endl;

        if (!ut->isSameSet(from, to))
        {
            cost += w;
            ut->unionSet(from, to);
        }
    }
    // cout << "Max Cost : " << cost << endl;
    return cost;
}
int tc = 1;
void solve()

{
    no_of_houses;
    cin >> no_of_houses;

    nodes = no_of_houses + 1;

    graph.resize(nodes);
    graph.clear();

    ll from, to, w;
    while (true)
    {
        cin >> from >> to >> w;
        if (from == 0 && to == 0 && w == 0)
            break;

        graph.pb(make_pair(w, make_pair(from, to)));
        // graph.pb({w,to,from});
    }

    //Printing Graph
    // cout << "Printing Graph" << endl;
    // for (int i = 0; i < graph.size(); i++)
    // {
    //     int from = graph[i].first;
    //     int to = graph[i].second.first;
    //     int w = graph[i].second.second;
    //     cout << "Weight :" << w << " " << from << " " << to << endl;
    // }

    cout << "Case " << tc++ << ": ";
    int answer = MST() + MaxST();
    if (answer % 2 == 0)
    {
        cout << answer / 2 << endl;
    }
    else
        cout << answer << "/2" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}