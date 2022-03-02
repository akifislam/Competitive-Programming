//Dynamic Programming on 1100??!
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long int N;
vector<ll> DP;
vector<ll> vec;

ll DynamicProgramming(ll src)
{
    if (src >= N)
        return 0;
    if (DP[src] != 0)
        return DP[src];

    DP[src] = vec[src] + DynamicProgramming(src + vec[src]);
    return DP[src];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> N;
        DP.clear();
        DP.resize(N, 0);
        vec.resize(N + 1);

        for (int i = 0; i < N; i++)
        {
            cin >> vec[i];
        }

        //DP
        ll answer = 0;
        for (int i = 0; i < N; i++)
        {
            answer = max(answer, DynamicProgramming(i));
        }
        cout << answer << endl;
    }
}