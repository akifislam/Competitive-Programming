//Akif Islam (__SHERLOCK__)
//Date: 2021-07-12 09:49:41

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
    ll INF = 1e6 + 10;
    ll amount;
    cin >> amount;

    ll N;
    cin >> N;

    vector<ll> coins(N);
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    ll dp[10001];
    for (int i = 0; i < 10001; i++)
    {
        dp[i] = INF;
    }

    dp[0] = 0;

    ll paid = INF;
    ll required_coins = INF;

    for (auto c : coins)
    {
        for (int i = 10000; i > 1; i--)
        {
            if (i >= c && dp[i] > dp[i - c] + 1)
            {
                dp[i] = dp[i - c] + 1;
            }
        }
    }

    for (int i = amount; i <= 10000; i++)
    {
        if (dp[i] != INF)
        {
            paid = i;
            required_coins = dp[i];
            break;
        }
    }
    cout << paid << " " << required_coins << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}