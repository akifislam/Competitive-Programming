//__SHERLOCK__
//Commitment leads to action.
// Failure is the sign that I am trying
// Got an awesome idea with DFS to solve this problem :)
// Hope it will work
//Date: 2021-04-29 09:07:31

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

vector<vector<pair<int, int>>> graph(1000);
bool visited[30001];
int tc = 1;
int max_dist = -1;
int node = -1;

//Two Vector to Save Distance
vector<int> left_nodes;
vector<int> right_nodes;

void SUNDAY_MONDAY_CLOSE()
{
    max_dist = -1;
    node = -1;
    memset(visited, false, sizeof(visited));
    node = -1;
}

void DFS(int x, int dist)
{
    if (visited[x])
        return;
    // cout << " Dist : " << dist << endl;

    if (dist > max_dist)
    {
        max_dist = dist;
        node = x;
        // cout << "Max Distance : " << max_dist << endl;
        // cout<<"Farthest Node : "<<node<<endl;
    }

    visited[x] = true;
    for (int i = 0; i < graph[x].size(); i++)
    {
        DFS(graph[x][i].first, dist + graph[x][i].second);
    }
}

void DFS2(int x, int dist, vector<int> &v)
{

    if (visited[x])
        return;
    // cout << "X = "<<x<<" " <<"Dist: " << dist << endl;

    v[x] = dist;

    visited[x] = true;
    for (int i = 0; i < graph[x].size(); i++)
    {
        DFS2(graph[x][i].first, dist + graph[x][i].second, v);
    }
}

void solve()
{
    int N;
    cin >> N;
    SUNDAY_MONDAY_CLOSE(); //RESET

    graph.clear();
    left_nodes.clear();
    right_nodes.clear();
    graph.resize(N);
    left_nodes.resize(N);
    right_nodes.resize(N);

    int n1, n2, w;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> n1 >> n2 >> w;
        graph[n1].push_back(make_pair(n2, w));
        graph[n2].push_back(make_pair(n1, w));
    }

    cout << "Case " << tc++ << ":" << endl;

    // Task 1 : DFS from Any Node
    // Task 2 : DFS from Node (Output of Task 1)
    // Task 3 : Save 2 Vector From Each Side Traversal

    DFS(0, 0);
    int farthest_node_1 = node;
    // cout << "Farthest 1 : " << node << endl;

    SUNDAY_MONDAY_CLOSE(); //RESET

    DFS(farthest_node_1, 0);
    int farthest_node_2 = node;
    // cout << "Farthest 2 : " << node << endl;

    SUNDAY_MONDAY_CLOSE();

    // cout<<"Visited Array"<<endl;
    // for (int i = 0; i < N; i++)
    // {
    //     cout<<visited[i]<<" ";
    // }
    // cout<<endl;

    DFS2(farthest_node_1, 0, left_nodes);
    // cout << left_nodes;

    SUNDAY_MONDAY_CLOSE();
    DFS2(farthest_node_2, 0, right_nodes);
    // cout << right_nodes;

    for (int i = 0; i < N; i++)
    {
        cout << max(left_nodes[i], right_nodes[i]) << endl;
    }
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