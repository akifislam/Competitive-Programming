//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-28 15:12:33

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
vector<vector<pair<int, int>>> graph(2);
vector<int> answer;
bool visited[30000];
int dist = 0;
int tc = 1;

void DFS(int x)
{
    if (visited[x])
        return;

    cout << "Traverrsing : " << x << endl;
    
    //Leaf Node Search
    bool leaf = true;
    for (int i = 0; i < graph[x].size(); i++)
    {
        if(!visited[graph[x][i].first]) {
            leaf = false;
            break;
        }
    }
    if(leaf) cout<<"Leaf Node : "<<x<<endl;
    

    visited[x] = true;
    for (int i = 0; i < graph[x].size(); i++)
    {
        DFS(graph[x][i].first);
    }
}
void solve()
{
    int N;
    cin >> N;
    graph.resize(N);
    int n1, n2, input;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> n1 >> n2 >> input;
        graph[n1].push_back(make_pair(n2, input));
        graph[n2].push_back(make_pair(n1, input));
        // weight[n1][n2] = input;
        // weight[n2][n1] = input;
    }
    DFS(0);
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