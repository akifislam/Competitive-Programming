//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-04 11:03:46

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
char arr[501][501];
int dp[501][501];
bool visited[501][501];
bool revisited[501][501];
int crystal_found = 0;
int tc = 1;

int m, n, Q;

void Nuclear_Bomb()
{
    memset(dp, -1, sizeof(dp));
    memset(visited, 0, sizeof(visited));
    memset(revisited, 0, sizeof(revisited));
    crystal_found = 0; //Extra Safety
}
bool isValid(int i, int j)
{
    if (i >= 1 && i <= m && j >= 1 && j <= n && (arr[i][j] != '#'))
        return true;
    return false;
}

// It change the values of crystal_found.
void DFS_1(int i, int j)
{
    if (visited[i][j])
        return;

    visited[i][j] = true;

    if (arr[i][j] == 'C')
        crystal_found++;

    for (int xx = 0; xx < 4; xx++)
    {
        int new_x = i + dx[xx];
        int new_y = j + dy[xx];

        if (isValid(new_x, new_y))
            DFS_1(new_x, new_y);
    }
}

void DFS_2(int i, int j, int crystal_value)
{
    if (revisited[i][j])
        return;
    revisited[i][j] = true;
    dp[i][j] = crystal_value;

    for (int p = 0; p < 4; p++)
    {
        int new_x = i + dx[p];
        int new_y = j + dy[p];

        if (isValid(new_x, new_y))
            DFS_2(new_x, new_y, crystal_value);
    }
}

void solve()
{
    Nuclear_Bomb();

    cin >> m >> n >> Q;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Case " << tc++ << ":" << endl;
    while (Q--)
    {
        int x, y;
        cin >> x >> y;

        if (dp[x][y] != -1)
        {
            cout << dp[x][y] << endl;
            continue;
        }

        crystal_found = 0;
        DFS_1(x, y);
        DFS_2(x, y, crystal_found);
        // cout << dp[x][y] << endl;
        // for (int i = 1; i <= m; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         cout << dp[i][j]<<" ";
        //     }
        //     cout << endl;
        // }
        cout << dp[x][y] << endl;
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