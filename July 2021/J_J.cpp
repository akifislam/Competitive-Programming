#include <stdio.h>

const int MOD = 1e9;
int dp[1000005];

int main()
{

    int i, j;
    int targetSum;
    scanf("%d", &targetSum);
    // int nums={}
    dp[0] = 1;
    for (j = 1; j <= targetSum; j++)
    {
        if (j % 2 == 1)
            dp[j] = dp[j - 1];
        else
            dp[j] = (dp[j - 1] + dp[j / 2]) % MOD;

        dp[j] %= MOD;
    }

    printf("%d\n", dp[targetSum]);

    return 0;
}