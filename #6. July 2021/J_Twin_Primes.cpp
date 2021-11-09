//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-06 20:49:51

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

namespace Prime
{
    using u64 = uint64_t;
    int sieved = -1;
    vi primeNumber;
    vi status;
    bool Check(int N, int Pos) { return (bool)(N & (1 << Pos)); }
    int Set(int N, int Pos) { return N = (N | (1 << Pos)); }

    void bitSieve(int mx)
    {
        sieved = mx;
        status.resize((mx >> 5) + 2, 0);
        int sq = (int)round(sqrt(mx));
        primeNumber.push_back(2);
        for (int i = 3; i <= sq; i = i + 2)
        {
            if (!Check(status[i >> 5], i & 31))
            {
                primeNumber.push_back(i);
                for (int j = i * i; j <= mx; j += i << 1)
                {
                    status[j >> 5] = Set(status[j >> 5], j & 31);
                }
            }
        }
        sq++;
        if (sq % 2 == 0)
            sq++;
        for (int i = sq; i < mx; i += 2)
        {
            if (!Check(status[i >> 5], i & 31))
                primeNumber.push_back(i);
        }
    }

}
using namespace Prime;
vector<pair<ll, ll>> couple_primes;

void get_pairs()
{

    // 2,3,5,8,11,13,17
    ll SIZE = primeNumber.size();
    // cout << "P S" << SIZE << endl;
    for (ll i = 1; i < SIZE; i++)
    {
        if (primeNumber[i] - primeNumber[i - 1] == 2)
            couple_primes.pb({primeNumber[i - 1], primeNumber[i]});
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    bitSieve(1e7 + 9900000);
    get_pairs();
    // cout << "Size of Couple Prime : " << couple_primes.size() << endl;

    ll input = 1;

    // cin>>input;
    while (cin >> input)
    {

        cout << "(" << couple_primes[input - 1].first << ", " << couple_primes[input - 1].second << ")" << endl;
    }
    return 0;
}