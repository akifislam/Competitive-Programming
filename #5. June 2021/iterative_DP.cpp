//Akif Islam (__SHERLOCK__)
//Date: 2021-06-04 12:21:21

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
int arr[1000][1000];

void solve()
{

    int m, n;
    cin >> m >> n;

    //Iterative DP
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            //If Boundary
            if (i == m - 1 || j == n - 1)
                arr[i][j] = 1;
            else
            {
                arr[i][j] = arr[i + 1][j] + arr[i][j + 1];
            }
        }
    }

    cout << arr[0][0] << endl;

    //Printing

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
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