//Akif Islam (__SHERLOCK__)
//Date: 2021-08-09 05:58:02

// No Testcase
// No Editorial
//Implementation Challenge

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
    cin >> n;

    int x = 0;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        if (str[0] == '+' || str[2] == '+')
            x++;
        else
            x--;
    }

    cout << x << endl;
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