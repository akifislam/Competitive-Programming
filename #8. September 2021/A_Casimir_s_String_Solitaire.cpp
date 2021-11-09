//Akif Islam (__SHERLOCK__)
//Date: 2021-09-28 20:38:38
// Ask Less, Practise More :)

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
    string str;
    cin >> str;

    ll SIZE = str.size();
    ll countB = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (str[i] == 'B')
            countB++;
    }

    if (countB == SIZE - countB)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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