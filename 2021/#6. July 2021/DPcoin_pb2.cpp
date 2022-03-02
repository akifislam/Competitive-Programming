// Unlimited Coins
// How many coins are required to get the sum?


/*
Question : 02
Author : Aminul

Given 3 coins : 1 2 5
You can use unlimited number-of-times.
Find the minimum number of coin required to make 'X' using all of these.


// 7 + 7 + 7 + 2 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int no_of_coins;
    cin >> no_of_coins;

    int MAX_SIZE = 1e5;
    int dp[MAX_SIZE + 1];

    for (int i = 0; i < MAX_SIZE + 1; i++)
    {
        dp[i] = 1e3;
    }
    vector<int> coins(no_of_coins);

    for (int i = 0; i < no_of_coins; i++)
    {
        cin >> coins[i];
    }

    int targetCoin;
    cin >> targetCoin;

    dp[0] = 0; // O Tk banate 0 ta Coin lage.

    for (int i = 1; i <= targetCoin; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            int temp = i - coins[j];
            if (temp >= 0)
            {
                dp[i] = min(dp[i],1 + dp[temp]);
            }
        }
    }
    cout << dp[targetCoin] << endl;
}
