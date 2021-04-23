//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-23 13:20:22
 
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
    int no_of_teams;
    cin >> no_of_teams;
 
    // (n-1) match played
    int team_matches = no_of_teams - 1;
 
    // If team_matches even, then half win, half odd.
    //Creating Sequence
    vector<int> sequence;
 
    // If Even match played, then half win, half lost
    if (team_matches % 2 == 0)
    {
        //Half Win
        for (int i = 0; i < team_matches / 2; i++)
            sequence.pb(1);
        //Half Lose
        for (int i = 0; i < team_matches / 2; i++)
            sequence.pb(-1);
    }
    //Odd Match Played, 1 Tie, Rest Half Win, Rest Half Lose
 
    else
    {
        //Half Win
        for (int i = 0; i < team_matches / 2; i++)
            sequence.pb(1);
 
        // One Tie
        sequence.pb(0);
 
        //Half Lose
        for (int i = 0; i < team_matches / 2; i++)
            sequence.pb(-1);
    }
 
    // Check
    //Print
    for (int i = 0; i < no_of_teams; i++)
    {
        for (int j = 0; j < team_matches - i; j++)
        {
            cout << sequence[j] << " ";
        }
    }
    cout << endl;
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