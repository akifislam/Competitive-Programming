//Akif Islam 
//Date: 2021-07-13 10:10:33
//Order Doesn't Matter 

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

vector<ll> nums;

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
    ll targetSum;
    cin >> targetSum;

    ll dp[targetSum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (ll i = 1; i <= targetSum; i++)
    {
        for (auto x : nums)
        {
            if (i - x >= 0)
            {
                dp[i] += dp[i - x];
            }
        }
    }
    for (int i = 0; i <= targetSum; i++)
    {
        cout << dp[i] << " ";
    }
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