#include <bits/stdc++.h>
using namespace std;

// Passing Bad Days :(


void solve()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int S;

    int distance = abs(X - Y);
    S = distance * 2;
    

        if (X > S || Y > S || Z > S)
    {
        cout << "-1" << endl;
        return;
    }

    else
    {
        int res = Z + distance;
        if (res > S)
            res = res % S;
        if (res != X && res != Y)
            cout << res << endl;
        else
            cout << "-1" << endl;
    }
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