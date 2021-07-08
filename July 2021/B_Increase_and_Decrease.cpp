 //Documentation :


    
    /* If the total sum is divisible by N, 
    we can get N as answer. Because at the time, 
    we can reach to its average value
     by those operations.

     By why the answer will always N-1 otherwise?
     because we can process N-1 element by letting the last element as the second pair.
     Like 3 11 17;
     3+11+17 = 31 is not divislbe by 3.
     So the answer is 2.
     How?
     We can reach to 7 from 3 and 11.
     Add 4 to 3, Subtract 4 to 17.
     So, 7 11 13
     Similarly, Sub 4 from 11, add 4 to 13,
     So, 7  7  17
     So ===2

*/

// Akif Islam

//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-02 22:11:35

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

   
    ll N;
    cin >> N;

    vector<ll> vec(N);
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }

    ll answer = N - 1;
    if (sum % N == 0)
        cout << N << endl;
    else
        cout << N - 1 << endl;
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

//