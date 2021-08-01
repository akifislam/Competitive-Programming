//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-29 21:06:51

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long int

void solve()
{
    int N, K;
    scanf("%lld %lld", &N, &K);

    int arr[N + 1];

    map<int, int> freq;
    map<int, vector<int>> index;
    bool hasDuplicate = false;
    int ans = -INT_MAX + 2;

    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &arr[i]);

        freq[arr[i]]++;
        index[arr[i]].push_back(i);

        if (freq[arr[i]] > 1 && !hasDuplicate)
        {
            hasDuplicate = true;
            int i1 = index[arr[i]][0];
            int j1 = index[arr[i]][1];
            int x = (i1 * j1) - K * (arr[i1] | arr[j1]);
            ans = x;
        }
    }
    // if (hasDuplicate)
    // {
    //     printf("%d\n", ans);
    //     return;
    // }

    int temp;
    int sj, si;

    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            temp = (i * j) - K * (arr[i] | arr[j]);
            if (ans < temp)
            {
                ans = temp;
                si = arr[i];
                sj = arr[j];
            }
        }
    }
    printf("%lld from (%lld,%lld)\n", ans, si, sj);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    scanf("%lld", &test);
    while (test--)
    {
        solve();
    }
    return 0;
}