//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-04 20:29:01

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

    ll no_of_dormitories, no_of_letters;
    cin >> no_of_dormitories >> no_of_letters;

    ll dormitory[no_of_dormitories+1];
    // ll letters[no_of_letters];
    ll input;

    ll sum = 0;

    dormitory[0] = 0;
    for (int i = 1; i <= no_of_dormitories; i++)
    {
        cin >> input;
        sum += input;
        dormitory[i] = sum; // 10 25 37
    }

    for (int i = 0; i < no_of_letters; i++)
    {
        cin>>input;
        ll dor_no = lower_bound(dormitory, dormitory+no_of_dormitories,input)-(dormitory);
        cout<<dor_no<<" "<<input-dormitory[dor_no-1]<<endl;
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