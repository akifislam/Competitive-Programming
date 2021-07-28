//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-24 11:50:23

#include <bits/stdc++.h>
using namespace std;
#define ll int

void solve()
{
    ll N, K;
    cin >> N >> K;

    vector<ll> vec(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    ll answer = 0;

    for (ll i = 0; i < N; i++)
    {
        if (binary_search(vec.begin(), vec.end(), vec[i] + K))
            answer++;
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