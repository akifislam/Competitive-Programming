//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-27 15:29:25

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

const int SIZE = 100005;
vector<int> graph[SIZE];

bool visited[SIZE];

long double answer = 0.0000;

void DFS(int x, long double depth)
{
    if (visited[x])
        return;
    // cout << "Node : " << x << ", Depth : " << depth << endl;
    visited[x] = true;

    bool isleafNode = true;

    for (auto v : graph[x])
    {
        isleafNode = false;
        DFS(v, depth + 1.000000);
    }
    if (isleafNode)
        answer += 0.0000;
    else
    {
    }
}
void solve()
{
    int no_of_cities;
    cin >> no_of_cities;

    int from, to;

    for (int i = 0; i < no_of_cities - 1; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to); //Directed Edge
        // graph[to].push_back(from); //Directed Edge
    }

    DFS(1, 0);
    // cout<<answer<<endl;
    long double result = answer / (long double)graph[1].size();
    // cout<<"REs"<<result<<endl;
    printf("%.15Lf\n", result);
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