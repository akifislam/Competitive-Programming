//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-13 19:54:56

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

void solve()
{
    string str;
    cin >> str;

    bool containsAB = false;
    bool containsBA = false;

    for (int i = 1; i < str.length(); i++)
    {
        if (str[i - 1] == 'A' && str[i] == 'B')
        {
            containsAB = true;
            for (int j = i + 2; j < str.length(); j++)
            {
                if (str[j- 1] == 'B' && str[j] == 'A')
                {
                    containsBA = true;
                   break;
                }
            }
            break;
      
        }
    }

    if (containsAB && containsBA)
    {
        cout << "YES" << endl;
        return;
    }

    containsAB = containsBA = false;
    // cout<<"Hi"<<endl;
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i - 1] == 'B' && str[i] == 'A')
        {
            containsAB = true;
            for (int j = i + 2; j < str.length(); j++)
            {
                if (str[j - 1] == 'A' && str[j] == 'B')
                {
                    containsBA = true;
                    break;
                }
            }
            break;
        }
    }
    if (containsAB && containsBA)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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