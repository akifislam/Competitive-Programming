

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

string new_string;
int matchedchar = 0;

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;

    string str;
    cin >> str;
    string copied = str;

    ll c0 = 0, c1 = 0;
    ll SIZE = n;

    for (int i = 0; i < SIZE; i++)
    {
        if (str[i] == '0')
            c0++;
        else
            c1++;
    }

    ll cost_1 = (a + b) * n; // If we process one by one
    // cout << "Cost 1 : " << cost_1 << endl;
    ll cost_2 = 0;
    ll cost_3 = 0;

    //Case 02 :  Others

    vector<int> substrs;
    ll count = 0;
    //How many substring with 0?
    for (int i = 0; i < SIZE; i++)
    {
        count = 0;
        if (str[i] == '0')
        {
            for (int j = i; j < SIZE; j++)
            {
                if (str[j] == '0')
                {
                    str[j] = '*';
                    count++;
                }
                else
                    break;
            }
            substrs.push_back(count);
        }
    }

    for (auto x : substrs)
    {
        cost_2 += ((a * x) + b);
    }
    cost_2 += ((a * c1) + b);

    //Third Case
    str = copied;

    vector<int> substrs2;
    count = 0;
    //How many substring with 0?
    for (int i = 0; i < SIZE; i++)
    {
        count = 0;
        if (str[i] == '1')
        {
            for (int j = i; j < SIZE; j++)
            {
                if (str[j] == '1')
                {
                    str[j] = '*';
                    count++;
                }
                else
                    break;
            }
            substrs2.push_back(count);
        }
    }
    // cout << substrs2 << endl;

    for (auto xx : substrs2)
    {
        cost_3 += ((a * xx) + b);
    }
    cost_3 += ((a * c0) + b);

    cout << max(max(cost_1, cost_2), cost_3) << "\n";
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