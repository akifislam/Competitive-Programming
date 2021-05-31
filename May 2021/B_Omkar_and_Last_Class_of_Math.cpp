//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-27 20:04:59

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long

void solve()
{
    ll N;
    cin >> N;

    if (N % 2 == 0)
    {
        cout << N / 2 << " " << N / 2 << endl;
    }
    else
    {
        ll a = 0, b = 0, sq;

        for (ll i = 2; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                a = N / i;
                b = N - a;

                break;
            }
        }
        if (a == 0 || b == 0)
            cout << 1 << " " << N - 1 << endl;
        else
            cout << a << " " << b << endl;
    }
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