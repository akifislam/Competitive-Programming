/*
Question : 01
Author : Aminul 

Given 3 coins : 2 5 7
Make 14
Using one can only once.

Note : X can be 0 TK <= X <= 8 TK
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int no_of_coins;
    cin >> no_of_coins;

    vector<int> coins(no_of_coins);

    for (int i = 0; i < no_of_coins; i++)
    {
        cin >> coins[i];
    }

    int targetCoin;
    cin >> targetCoin;

    int dp[targetCoin + 1];

    for (int i = 1; i <= targetCoin; i++)
    {
        dp[i] = 1000;
    }

    dp[0] = 0; // 0 TK 0 coin use kore banano Jay

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = 1; j <= targetCoin; j++)
        {
            if (coins[i] <= j)
            {
                int temp = j - coins[i]; //0
                if (coins[i] != temp)
                    dp[j] = min(dp[j], 1 + dp[temp]);
            }
        }
    }

    cout << dp[targetCoin] << endl;
    for (int i = 0; i <= targetCoin; i++)
    {
        if (dp[i] == 1000)
            cout << "X ";
        else
            cout << dp[i] << " ";
    }
    cout << endl;

}
