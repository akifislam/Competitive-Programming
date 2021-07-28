//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-24 13:14:17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;
char gap = 32;

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

// O (N^2) Solution

void solve()
{
    ll N, input;
    cin >> N;

    vector<ll> vec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    sort(All(vec));

    ll answer = 0;
    ll prev = -1;
    for (int i = 0; i < N; i++)
    {
        if (vec[i] == -1)
            continue;

        answer++;
        prev = vec[i];

        for (int j = i; j < N; j++)
        {
            if (vec[j] > prev)
            {
                prev = vec[j];
                vec[j] = -1;
            }
        }
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
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}