//Akif Islam (__SHERLOCK__)
//Date: 2021-08-09 06:12:10

// Challenge : 150 Implementation | Don't watch Editorial / Testcases | Inspired from Farhan132
// This is 2nd out of 150 (Implementation Training)

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

    int input;
    pair<int, int> index;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> input;

            if (input == 1)
                index = make_pair(i, j);
        }
    }

    cout << abs(2 - index.first) + abs(2 - index.second) << endl;
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