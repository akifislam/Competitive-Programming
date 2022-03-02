//Akif Islam (__SHERLOCK__)
//Date: 2021-08-01 13:04:09

#include <bits/stdc++.h>

using namespace std;

char gap = 32;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}

#define ll long long
#define pb push_back
#define All(x) (x).begin(), (x).end()

void solve()
{
    ll N;
    cin >> N;

    ll arr[2][N];

    //Step 1  : Take Input
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    //Step 2 : Change the equation to :
    // (ai - bi) + (aj-bj) > 0
    // So Make an array of ci = ai - bi;

    vector<ll> c(N);
    for (int i = 0; i < N; i++)
    {
        c[i] = arr[0][i] - arr[1][i];
    }

    //Now Sort Them :
    sort(All(c));
    // cout << c << endl;

    ll answer = 0;

    for (int i = 0; i < N; i++)
    {
        ll target = -c[i];

        auto ind = upper_bound(c.begin() + i + 1, c.end(), target);
        if (ind == c.end())
            continue;

        // cout << "Got : " << N - (ind - (c.begin())) << endl;
        answer += N - (ind - (c.begin()));
    }
    cout << answer << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}