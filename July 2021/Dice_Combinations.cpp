#include <bits/stdc++.h>
using namespace std;
#define ll int32_t
const ll SIZE = 1e6 + 5;
const ll MOD = 1e9 + 7;
// const ll MOD = 53;

ll dp[SIZE];

ll solve(ll N)
{
    if (N == 0)
        return 1;
    if (N <= 0)
        return 0;
    if (dp[N] != -1)
        return dp[N];

    int best = 0;

    for (ll i = 1; i <= 6; i++)
    {
        best += (solve(N - i)) % MOD;
        best %= MOD;
    }
    dp[N] = best;
    return best;
    //3
    // [1] [1] [2] []
}
int main()
{

    memset(dp, -1, sizeof(dp));
    ll N;
    cin >> N;
    cout << solve(N) << endl;
}