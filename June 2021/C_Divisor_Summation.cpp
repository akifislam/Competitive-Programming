//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-06-27 16:23:35

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// 1 2 4 5 10
void solve()
{
    ll N;
    cin >> N;
    if (N == 1)
    {
        cout << 0 << endl;
        return;
    }
    ll sum = 1;

    for (ll i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            sum += i;
            if (N / i != i)
                sum += N / i;
        }
    }

    cout << sum << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}