#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int targetCoin;
    cin >> targetCoin;

    int dp[coins.size() + 1][targetCoin + 1];

    dp[0][0] = 1; // 0ta Coin diye 0 Ekvabe Banano Jay

    // 0 Ta coin diye 1--targetCoin porjonto 0 vabe banano jay.
    for (int i = 1; i <= targetCoin; i++)
    {
        dp[0][i] = 0;
    }

    // 0,1,2,3 .. ta coin diye 0 banano jay 1 vabe.
    for (int i = 1; i <= coins.size(); i++)
    {
        dp[i][0] = 1;
    }

    //Tabulation
    for (int i = 1; i <= coins.size(); i++)
    {
        for (int j = 1; j <= targetCoin; j++)
        {
            if (j >= coins[i - 1])
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[coins.size()][targetCoin] << endl;
    //Print
    for (int i = 0; i <= coins.size(); i++)
    {
        for (int j = 0; j <= targetCoin; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}