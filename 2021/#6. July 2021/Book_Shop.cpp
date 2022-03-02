//Akif Islam (__SHERLOCK__)
//Date: 2021-07-16 07:22:10
//Milestone problem for DP :)

// Submitted with the help of this video
// YouTube Tutorial Link : https://youtu.be/MEXBU9SFy7Q

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
ll dp[1001][100005];

void solve()
{
    ll N, money;
    cin >> N >> money;

    vector<ll> prices(N);
    vector<ll> pages(N);

    for (int i = 0; i < N; i++)
    {
        cin >> prices[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> pages[i];
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= money; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= prices[i - 1])
                dp[i][j] = max(dp[i][j], pages[i - 1] + dp[i - 1][j - prices[i - 1]]);
        }
    }

    cout << dp[N][money] << endl;
    return;
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