#include <bits/stdc++.h>
using namespace std;
#define ll int32_t
const ll SIZE = 1e6 + 5;
const ll MOD = 1e9 + 7;
// const ll MOD = 53;

int main()
{

    memset(dp, -1, sizeof(dp));
    ll N;
    cin >> N;
    ll dp[N + 1];
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i >= j)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    cout << dp[N] << endl;
}