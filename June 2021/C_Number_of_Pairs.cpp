//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-06-10 21:40:00

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

multiset<ll> s;
ll n, l, r;

int countInRange(int num, int index)
{
    int left_index = -1;
    int right_index = -1;
    int SIZE = s.size();


    //finding left index
    ll targetNumber = (num - l)
    left_index = 
    // cout << "Left Index : " << left_index << endl;
    //finding right index
    for (int i = index - 1; i >= 0; i--)
    {
        if (num + vec[i] <= r)
        {
            right_index = i;
            break;
        }
    }
    // cout << "right Index : " << right_index << endl;

    // cout << "Num : " << num << endl;
    // cout << "Returing : " << max(right_index - left_index + 1, 0) << endl;
    // cout << "------" << endl;

    // if (left_index < right_index)
    // {
    if (left_index == -1 || right_index == -1)
    {
        // cout << "Returning 0" << endl;

        return 0;
    }
    else
    {
        // cout << "Returning : " << right_index - left_index + 1 << endl;

        return right_index - left_index + 1;
    }
}
// else
//     return 0;

void solve()
{
    s.clear();
    cin >> n >> l >> r;

    ll input;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input <= r)
            s.insert(input);
    }
    // 4 + 3 + 2 + 1

    ll SIZE = s.size();

    ll answer = 0;
    for (auto it = it.rbegin(); it != r.end(); it++)
    {
        answer += countInRange(*it, i);
    }
    cout << answer << endl;
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