// /__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-06 22:04:08

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

const int MAX = 500001;
vector<int> graph[MAX];
vector<int> answer;
vector<int> processed;

int cnt = 0;

void DFS(int src)
{
    if (processed[src])
        return;
    cnt++;
    // cout << "Count : " << cnt << endl;
    // cout << "Visiting : " << src << endl;
    processed[src] = 1;
    for (int i = 0; i < graph[src].size(); i++)
    {
        if (!processed[graph[src][i]])
            DFS(graph[src][i]);
    }
}

void update(int src, int val)
{
    if (processed[src])
        return;

    // cout << "Count : " << cnt << endl;
    // cout << "Visiting : " << src << endl;
    answer[src] = val;
    processed[src] = 1;
    for (int i = 0; i < graph[src].size(); i++)
    {
        if (!processed[graph[src][i]])
            update(graph[src][i], val);
    }
}
void solve()
{
    int nodes, groups;
    cin >> nodes >> groups;
    // graph.resize(nodes + 1);
    answer.resize(nodes + 1, 0);
    processed.resize(nodes + 1, 0);

    for (int i = 0; i < groups; i++)
    {
        int N;
        cin >> N;
        int prev, input;

        if (N > 0)
            cin >> prev;

        N--;

        while (N > 0)
        {
            cin >> input;
            graph[prev].pb(input);
            graph[input].pb(prev);
            N--;
            prev = input;
        }
        // cout << "OK" << endl;
    }

    for (int i = 1; i < nodes + 1; i++)
    {
        if (!answer[i])
        {
            cnt = 0;
            DFS(i);
            int ans = cnt;
            processed.clear();
            processed.resize(nodes + 1, 0);
            // cout<<visited<<endl;
            // cout << "Passing : " << ans << endl;
            update(i, ans);
        }
    }
    for (int i = 1; i <= nodes; i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
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