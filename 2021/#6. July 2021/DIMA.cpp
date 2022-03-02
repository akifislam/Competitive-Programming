//Akif Islam (__SHERLOCK__)
//Date: 2021-07-27 22:39:53

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
    int n, m;
    cin >> n >> m;

    int arr[501][501];
    int ans[501];
    int XOR = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
        XOR = XOR ^ arr[i][1];
        ans[i] = 1;
    }

    bool isOK = false;

    if (XOR != 0)
        isOK = true;
    else
    {
        for (int i = 1; i <= n && !isOK; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (arr[i][1] != arr[i][j])
                {
                    isOK = true;
                    ans[i] = j;
                    break;
                }
            }
        }
    }

    if (isOK)
    {
        cout << "TAK" << endl;
        for (int i = 1; i <=n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NIE" << endl;
    }
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