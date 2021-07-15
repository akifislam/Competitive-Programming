// Forcely Tring with DP
//Akif Islam
//Date: 2021-07-11 21:58:46

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

#ifdef AKIF
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')' << ':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ll long long

#define pb push_back

void solve()
{
    ll N;
    cin >> N;

    ll dp[N];
    memset(dp, 0, sizeof(dp));
    vector<ll> vec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    dp[N - 1] = 0;

    ll answer = 0;

    for (int i = N - 2; i >= 0; i--)
    {
        if (vec[i] <= vec[i + 1])
        {
            dp[i] = 1 + dp[i + 1];
            answer = max(answer, dp[i]);
        }
    }

    cout << answer + 1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}