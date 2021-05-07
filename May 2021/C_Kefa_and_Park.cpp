//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-06 17:23:18

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

const int MAX = 200005;
vector<int> hasCat;
vector<vector<int>> graph(1);

int answer = 0;
int nodes, catLimit, cat = 0;

vector<int> processed;

void DFS(int src, int prev, int catCount)
{

    if (processed[src])
        return;
    processed[src] = 1;

    if (!hasCat[src])
        catCount = 0;
    else
        catCount++;

    if (catCount > catLimit)
        return;

    bool isLeaf = true;

    for (int i = 0; i < graph[src].size(); i++)
    {
        if (graph[src][i] == prev)
            continue;
        isLeaf = false;
        if (!processed[graph[src][i]])
            DFS(graph[src][i], src, catCount);
    }
    if (isLeaf)
        answer++;
}
void solve()
{
    cin >> nodes >> catLimit;
    graph.resize(nodes + 1);
    hasCat.resize(nodes + 1, 0);
    processed.resize(nodes + 1, 0);

    for (int i = 1; i <= nodes; i++)
    {
        int input;
        cin >> input;
        hasCat[i] = input;
    }
    // cout<<hasCat<<endl;
    int from, to;
    for (int i = 0; i < nodes - 1; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    DFS(1, 0, 0);
    cout << answer << endl;
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