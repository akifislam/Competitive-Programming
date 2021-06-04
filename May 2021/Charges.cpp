//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-31 21:11:46

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

char toggle(char x)
{
    if (x == '1')
        return '0';
    else
        return '1';
}
void solve()
{
    ll N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    //Calculate Distance 1 --- N;

    ll dist = 0;

    for (int i = 1; i < N; i++)
    {
        if (str[i - 1] == str[i])
            dist += 2;
        else
            dist++;
    }
    // cout << "ini dis " << dist << endl;

    ll query;
    while (K--)
    {
        cin >> query;
        query--;

        if (N == 1)
        {
            cout << 0 << endl;
            continue;
        }

        if (query == 0)
        {
            str[query] = toggle(str[query]);

            if (str[query] == str[query + 1])
                dist++;
            else
                dist--;
        }

        else if (query == N - 1)
        {
            str[query] = toggle(str[query]);

            if (str[query] == str[query - 1])
                dist++;
            else
                dist--;
        }

        else
        {
            str[query] = toggle(str[query]);
            // 2 Pashei Alada
            if ((str[query - 1] == str[query + 1]) && (str[query] != str[query + 1]))
                dist -= 2;

            //3 Tai Eki
            else if ((str[query - 1] == str[query + 1]) && (str[query] == str[query + 1]))
                dist += 2;
        }
        // cout << str << endl;
        cout << dist << endl;
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