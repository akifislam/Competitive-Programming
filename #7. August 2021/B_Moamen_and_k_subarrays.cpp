#include <bits/stdc++.h>
using namespace std;

// Try with Simple Idea


#define ll long long int

void solve()
{
    ll TOTAL_NO, HAVE;
    cin >> TOTAL_NO >> HAVE;

    ll IN;

    vector<ll> INPUT_ORDER(TOTAL_NO);

    set<ll> SORTED;

    for (int i = 0; i < TOTAL_NO; i++)
    {

        cin >> INPUT_ORDER[i];

        //Input
        SORTED.insert(INPUT_ORDER[i]);
    }






    ll COUNT_SEG = 1;

    for (int i = 1; i < TOTAL_NO; i++)
    {
        auto it = SORTED.upper_bound(INPUT_ORDER[i - 1]);

        if (it == SORTED.end())
        {
            COUNT_SEG++;

            continue;
        }

        else if (INPUT_ORDER[i] != *it)
            COUNT_SEG++;
    }
    //oniqwf

    if (HAVE < COUNT_SEG)
        cout << "No" << endl;

    else

        cout << "Yes" << endl;

    //Done
}




int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}