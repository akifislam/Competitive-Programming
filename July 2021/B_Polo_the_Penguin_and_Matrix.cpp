//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-03 05:49:24

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

void solve()
{
    ll n, m, d;
    cin >> n >> m >> d;

    // n row, m column
    vector<int> num;
    int arr[m][n];
    bool isPossible = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            num.pb(arr[i][j]);
            if (isPossible && (arr[i][j] % d != 0))
            {
                isPossible = false;
                break;
            }
        }
    }

    if (!isPossible)
        cout << -1 << endl;

    else
    {
        sort(All(num));
        // 1 2 3 4 5 6
        int N = num.size();
        int median;
        if (N % 2 == 1)
        {
            median = num[N / 2];
            int answer = 0;
            for (int i = 0; i < N; i++)
            {
                answer += (abs(median - num[i]) / d);
            }
            cout << answer << endl;
        }

        else
        {
            int answer_1 = 0;
            int answer_2 = 0;

            // 1 2 3 4
            int median_1 = num[N / 2];
            int median_2 = num[N / 2 + 1];

            for (int i = 0; i < N; i++)
            {
                answer_1 += (abs(median_1 - num[i]) / d);
            }

            for (int i = 0; i < N; i++)
            {
                answer_2 += (abs(median_2 - num[i]) / d);
            }

            cout << min(answer_1, answer_2) << endl;
        }
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