// Nim Game Practise 01

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

int tc = 0;

void solve()
{
    int N;
    cin >> N;

    int moves[2][N];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> moves[i][j];
        }
    }

    int xorSum = 0;
    for (int i = 0; i < N; i++)
    {
        xorSum ^= (moves[1][i] - moves[0][i] - 1);
    }

    if (xorSum == 0)
    {
        cout << "Case " << ++tc << ": "
             << "black wins" << endl;
    }
    else
    {
        cout << "Case " << ++tc << ": "
             << "white wins" << endl;
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