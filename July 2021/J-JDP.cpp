//Akif Islam (__SHERLOCK__)
//Date: 2021-07-13 10:46:51

#include <bits/stdc++.h>

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

#define ll long long
#define pb push_back
#define All(x) (x).begin(), (x).end()

const ll SIZE = 1e6 + 5;
ll dp[SIZE];

vector<ll> nums;

ll solve(ll i, ll targetSum)
{

    if (targetSum == 0)
        return 1;
    if (targetSum < 0)
        return 0;
    if (i <= 0 && targetSum >= 1)
        return 0;

    return solve(i - 1, targetSum) + solve(i, targetSum - nums[i]);
}

void power_up()
{
    ll x = 1;
    while (x < 1000005)
    {
        nums.pb(x);
        x *= 2;
    }
    cout << nums << endl;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    ll N;
    cin >> N;
    cout << solve(nums.size(), N) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    power_up();
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}