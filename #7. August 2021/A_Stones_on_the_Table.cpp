//Akif Islam (__SHERLOCK__)
//Date: 2021-08-09 06:26:58

// Challenge : 150 Implementation | Don't watch Editorial / Testcases | Inspired from Farhan132
// This is 3 out of 150 (Implementation Training)

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
    int n;
    string str;

    cin >> n;
    cin>>str;

    cout << n - (unique(str.begin(), str.end()) - str.begin()) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}