
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int SS;
    cin >> SS;

    vector<int> V(SS);

    for (int i = 0; i < SS; i++)
    {
        cin >> V[i];
    }
    sort(V.begin(), V.end());

    int first = V[0];
    int count = 1;

    //Done

    for (int i = 1; i < SS; i++)
    {
        if (V[i] == first)
            count++;
        else

            break;

        //Found
    }
    cout << SS - count << endl;
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