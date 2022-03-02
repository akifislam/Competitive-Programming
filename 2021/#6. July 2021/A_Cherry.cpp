//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-29 20:46:00

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve()
{

    ll SIZE;

    cin >> SIZE;

    ll RES = -1125982;

    ll backval = -1258722;

    cin >> backval;

    //---

    ll xx;

    for (ll i = 1; i < SIZE; i++)
    {

        cin >> xx;

        RES = max(RES, backval * xx);

        backval = xx;
    }

    // OK

    cout << RES << endl;
}

int32_t main()
{
    int TT = 1;

    cin >> TT;

    
    while (TT--)
    {
        solve();
    }
    return 0;
}