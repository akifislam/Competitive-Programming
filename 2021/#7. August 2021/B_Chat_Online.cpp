//Akif Islam (__SHERLOCK__)
//Date: 2021-08-12 22:52:28
// Ask Less, Practise More :)

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
    int p, q, l, r;
    cin >> p >> q >> l >> r;

    bool isOnline[100000];
    memset(isOnline, false, sizeof(isOnline));

    // vector<pair<int, int>> fixed;
    vector<pair<int, int>> vari;

    int a, b;

    for (int i = 0; i < p; i++)
    {
        cin >> a >> b;
        // fixed.push_back(make_pair(a, b));
        for (int j = a; j <= b; j++)
        {
            //Online e thake
            isOnline[j] = true;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        vari.push_back(make_pair(a, b));
    }

    //Input Done

    //Process
    int ans = 0;
    
    for (int i = l; i <= r; i++)
    {
        for (int j = 0; j < q; j++)
        {
            if (isOnline[vari[j].first + i] || isOnline[vari[j].second + i])
            {
                // cout << i << " is Added" << endl;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}