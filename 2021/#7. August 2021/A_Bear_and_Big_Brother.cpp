//Akif Islam (__SHERLOCK__)
//Date: 2021-08-09 10:52:59

// Challenge : 150 Implementation | Don't watch Editorial / Testcases | Inspired from Farhan132
// This is 4th out of 150 (Implementation Training)

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
    int Limak, Bob;
    cin >> Limak >> Bob;

    int ans = 0;

    while (Limak <= Bob)
    {
        ans++;
        Limak *= 3;
        Bob *= 2;
    }

    cout << ans << endl;
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