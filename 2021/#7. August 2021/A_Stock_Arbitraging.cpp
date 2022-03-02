//Akif Islam (__SHERLOCK__)
//Date: 2021-08-17 10:37:10
//Passing some WORST DAYs of my life :(

#include <bits/stdc++.h>

using namespace std;

char gap = 32;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}

#define ll long long
#define pb push_back
#define All(x) (x).begin(), (x).end()

void solve()
{

    int buy, sell, burles;
    cin >> buy >> sell >> burles;

    vector<int> B(buy);
    vector<int> S(sell);

    for (int i = 0; i < buy; i++)
    {
        cin >> B[i];
    }

    sort(All(B));

    for (int i = 0; i < sell; i++)
    {
        cin >> S[i];
    }

    sort(All(S));

    int have = burles;
    int count = burles / B[0];    // 11/2 = 5;
    have = have - (count * B[0]); // Left 1

    have += (count * S.back());

    if (have < burles)
        cout << burles << endl;
    else
        cout << have << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}