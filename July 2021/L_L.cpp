//Akif Islam (__SHERLOCK__)
//Date: 2021-07-12 09:15:41

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

void solve()
{
    ll N;
    cin >> N;

    ll dp[N + 1];
    memset(dp, 0, sizeof(dp));

    // Minimum 3 ta Brick diye Stair banano jay.
    dp[3] = 1;

    for (ll i = 4; i <= N; i++)
    {

        dp[i] = 1 + dp[i - 1];
    }

    for (ll i = 1; i <= N; i++)
    {
        cout << dp[i] << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}