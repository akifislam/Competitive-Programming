#include <bits/stdc++.h>
using namespace std;
#define INF 1e6

int main()
{
    vector<int> coins;

    int no_of_coins;
    cin >> no_of_coins;

    for (int i = 0; i < no_of_coins; i++)
    {
        int input;
        cin >> input;
        coins.push_back(input);
    }

    int targetSum;
    cin >> targetSum;

    int dp[targetSum];
    int first[targetSum];

    for (int i = 0; i <= targetSum; i++)
    {
        dp[i] = INF;
    }

    dp[0] = 0;

    for (int i = 1; i <= targetSum; i++)
    {
        for (auto c : coins)
        {
            if (i - c >= 0 && dp[i - c] + 1 < dp[i])
            {
                dp[i] = dp[i - c] + 1;
                first[i] = c;
            }
        }
    }
    cout << dp[targetSum] << endl;

    while (targetSum > 0)
    {
        cout << first[targetSum] << " ";
        targetSum -= first[targetSum];
    }
}
