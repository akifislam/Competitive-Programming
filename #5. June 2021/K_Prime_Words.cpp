//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-06-29 03:25:36

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

map<char, int> letterValues;

void Fire_Letters()
{
    char lowercase = 'a';

    //Lowercase Hashing
    for (int i = 1; i <= 26; i++)
    {
        letterValues[lowercase] = i;
        lowercase++;
    }

    //Uppercase Hasing
    char uppercase = 'A';
    for (int i = 27; i <= 52; i++)
    {
        letterValues[uppercase] = i;
        uppercase++;
    }

    // for (auto xx : letterValues)
    // {
    //     cout << xx.first << " -->" << xx.second << endl;
    // }
}

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    string input;

    while (cin >> input)
    {
        int length = input.size();
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += letterValues[input[i]];
        }
        // cout << "Sum is : " << sum << endl;

        if (isPrime(sum))
            cout << "It is a prime word." << endl;
        else
            cout << "It is not a prime word." << endl;
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
    Fire_Letters();
    while (test--)
    {
        solve();
    }
    return 0;
}