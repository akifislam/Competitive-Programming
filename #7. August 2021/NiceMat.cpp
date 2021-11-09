//Akif Islam (__SHERLOCK__)
//Date: 2021-08-20 10:57:54
//Learning from Tutorial

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

#define int long long int
#define pb push_back
#define All(x) (x).begin(), (x).end()

void solve()
{

    int n, m;
    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0; //?

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp[3] = {arr[i][j], arr[i][m - j - 1], arr[n - i - 1][j]};
            sort(temp, temp + 3);

            int median = temp[1];

            ans += (median - temp[0]) + (temp[2] - median); // Op Calculate
            arr[i][j] = arr[i][m - j - 1] = arr[n - i - 1][j] = median;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}