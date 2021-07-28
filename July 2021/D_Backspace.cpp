//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-22 21:56:45

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
    string S;
    string T;
    cin >> S >> T;

    int s_size = S.size();
    int t_size = T.size();
    if (s_size < t_size)
    {
        cout << "NO" << endl;
        return;
    }
    vector<int> pos;

    for (int i = 0; i < s_size; i++)
    {
        if (S[i] == T[0])
            pos.pb(i);
    }

    int i, j;
    int POS_SIZE = pos.size();
    int p = 0;
    string new_string;
    int lastpush = 0;

    for (i = 0; i < POS_SIZE; i++)
    {
        new_string = "";
        p = 0;

        for (j = pos[i]; j < s_size; j++)
        {

            if (S[j] == T[p] && p < t_size && ((j - lastpush <= 1) || (j - lastpush) % 2 == 1))
            {
                new_string.pb(S[j]);
                lastpush = j;
                p++;
            }
        }
        // cout << new_string << endl;

        // cout << (s_size - (lastpush+ 1)) << endl;

        if (new_string == T && (s_size - (lastpush + 1)) % 2 == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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