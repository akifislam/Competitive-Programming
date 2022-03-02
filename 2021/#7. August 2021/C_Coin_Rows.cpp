//Akif Islam (__SHERLOCK__)
//Date: 2021-08-01 03:19:09

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
    int N;
    cin >> N;
    int grid[2][N];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }
    int dp[N + 5] = {0};

    for (int i = N - 1; i >= 0; i--)
    {
        dp[i] += dp[i + 1] + grid[0][i];
    }
    // 1 3 7
    // 3 5 1
    //-------
    int score = 0;

    for (int i = 0; i < N; i++)
    {
        if (score + grid[1][i] <= dp[i + 1])
        {
            score += grid[1][i];
    
        }
        else
        {
            score = max(dp[i + 1], score);
            break;
        }
    }
    cout << score << endl;
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