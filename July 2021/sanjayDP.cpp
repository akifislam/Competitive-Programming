#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    int a[2][n];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    ll dp[n + 2] = {0};

    ll score = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] += dp[i + 1] + a[0][i];
    }

   

    for (int i = 0; i < n; i++)
    {
     
        cout << "Sc : " << score << endl;
        if (score + a[1][i] > dp[i + 1])
        {
            score = max(score, dp[i + 1]);
            break;
        }
        score += a[1][i];
    }
    cout << score << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
    return 0;
}