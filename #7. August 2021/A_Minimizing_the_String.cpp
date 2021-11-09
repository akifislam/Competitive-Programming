//Akif Islam (__SHERLOCK__)
//Date: 2021-08-17 11:05:57
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
    int n;
    cin >> n;

    string str;
    cin >> str;

    bool found = false;

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] > str[i + 1])
        {
            str[i] = '*';
            found = true;
            break;
        }
    }
    if (!found)
        n--;

    for (int i = 0; i < n; i++)
    {
        if (str[i] != '*')
            cout << str[i];
    }
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