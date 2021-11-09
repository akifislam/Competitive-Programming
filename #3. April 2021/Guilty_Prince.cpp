//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-30 12:10:47

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

char graph[25][25];
bool visited[25][25];
int answer = 0;
int W, H, start_i, start_j;
int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};

int tc = 1;

bool isOkay(int i, int j)
{
    if ((i >= 0 && i < H) && (j >= 0 && j < W))
        return true;
    return false;
}

void DFS(int i, int j)
{
    cout<<"Visiting Cell :"<<i<<" "<<j<<endl;
    if (visited[i][j])
        return;

    visited[i][j] = true;
    answer++;

    for (int x = 0; x < 4; x++)
    {
        int next_i = i + dx[x];
        int next_j = j + dy[x];
        if (isOkay(next_i, next_j))
            DFS(next_i, next_j);
    }
}

void solve()
{
    answer = 0;
    memset(visited, false, sizeof(visited));

    cin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == '#')
                visited[i][j] = true;

            if (graph[i][j] == '@')
            {
                start_i = i;
                start_j = j;
            }
        }
    }
    DFS(start_i, start_j);
    printf("Case %d: %d\n",tc++,answer);
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