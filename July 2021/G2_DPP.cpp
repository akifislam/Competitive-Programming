//Akif Islam (__SHERLOCK__)
//Date: 2021-07-13 09:25:02

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

#define ll long long int
#define pb push_back
#define All(x) (x).begin(), (x).end()
int tc = 1;

void solve()
{
    cout << "Case " << tc++ << ": ";
    ll N;
    cin >> N;

    vector<ll> vec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    if (N == 0)
    {
        cout << 0 << endl;
        return;
    }
    else if (N == 1)
    {
        cout << vec[0] << endl;
        return;
    }

    ll dp[N];
    memset(dp, 0, sizeof(dp));
    
    dp[N - 1] = vec[N - 1];
    dp[N - 2] = vec[N - 2];

    //DP
    for (int i = N - 3; i >= 0; i--)
    {
        dp[i] = max(dp[i + 1], vec[i] + dp[i + 2]);
    }

    dp[0] = max(dp[0], dp[1]);
    cout << dp[0] << endl;
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