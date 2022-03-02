//Recursive Solution

#include <bits/stdc++.h>
using namespace std;
#define INF 1e6

int dp[1000];
vector<int> coins;

int solve(int x)
{
    if (x < 0)
        return INF;
    if (x == 0)
        return 1;
    if (dp[x] != -1)
        return dp[x];

    int best = INF;

    for (auto c : coins)
    {
        best = min(best, solve(x - c) + 1);
    }
    dp[x] = best;
    return best;
}

int main()
{
    memset(dp, -1, sizeof(dp));

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

    cout << solve(targetSum) << endl;
}
