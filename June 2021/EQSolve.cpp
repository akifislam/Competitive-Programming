//Dynamic Programming Solution
// BruteForce Checker
 
//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-28 20:25:42
 
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
 
ll num[8] = {11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
unordered_map<ll, bool> DP;
 
void BruteForceChecker()
{
    int counter = 0;
    for (int i = 1200; i < 1400; i++)
    {
        bool isPossible = false;
 
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
            {
                if ((11 * j) + (111 * k) == i)
                {
                    counter++;
                    cout << i << " Possible" << endl;
                    isPossible = true;
                    break;
                }
                if (isPossible)
                    break;
            }
            if (isPossible)
                break;
        }
    }
    cout << "Found : " << counter << endl;
}
 
bool canSum(ll targetSum)
{
 
    if (targetSum == 0 || targetSum>1500)
        return true;
 
    if (targetSum < 0)
        return false;
 
 
    if (DP.find(targetSum) != DP.end())
        return DP[targetSum];
 
    for (int i = 0; i < 8; i++)
    {
        ll reminder = targetSum - num[i];
 
        if (canSum(reminder) == true)
        {
            DP[reminder] = true;
            return true;
        }
    }
 
    DP[targetSum] = false;
    return false;
}
 
void solve()
{
    ll N;
    cin >> N;
 
    if (canSum(N))
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
    BruteForceChecker();
    // cin >> test;
    while (test--)
    {
        // solve();
    }
    return 0;
}