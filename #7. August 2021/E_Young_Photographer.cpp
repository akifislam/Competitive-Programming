//Akif Islam (__SHERLOCK__)
//Date: 2021-08-11 22:10:35
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
    int n, pos;
    cin >> n >> pos;

    int ans = 0;

    int from, to;
    int left = 0;
    int right = 1e6;

    for (int i = 0; i < n; i++)
    {
        cin >> from >> to;

        if (from > to)
            swap(from, to);

        left = max(left, from);
        right = min(right, to);
    }

    if (left > right)
    {
        cout << -1 << endl;
    }
    else
    {
        if (left <= pos && right >= pos)
            cout << 0 << endl;
        else
        {
            if (left > pos)
                cout << left - pos << endl;
            else
                cout << pos-right << endl;
        }
    }
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