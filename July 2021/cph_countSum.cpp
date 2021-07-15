//Iterative Solution

#include <bits/stdc++.h>
using namespace std;
#define INF 1e6

int main()
{
    int no_of_coins;
    cin >> no_of_coins;
    vector<int> coins;

    for (int i = 0; i < no_of_coins; i++)
    {
        int input;
        cin >> input;
        coins.push_back(input);
    }

    int targetSum;

    cin >> targetSum;
    int dp[targetSum + 1];

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = 1; j <= targetSum; j++)
        {
            if (j >= coins[i])
            {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
    }

    for (int i = 0; i <= targetSum; i++)
    {
        cout << dp[i] << " ";
    }
}
