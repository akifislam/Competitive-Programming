//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-26 20:12:27

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N, Q;
    scanf("%d %d", &N, &Q);

    int type, num;
    set<int> s;

    while (Q--)
    {
        scanf("%d %d", &type, &num);

        if (type == 1)
        {
            s.insert(num);
        }
        else
        {
            auto it = s.lower_bound(num);
            if (it ==s.end())
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", *it);
            }
        }
    }
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
// #ifdef AKIF
// #endif
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}