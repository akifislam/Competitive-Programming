#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

bool solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll sum = 0;

    //Checking from left
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum <= 0)
            return 0;
    }

    sum = 0;
    //Checking from Right
    for (int i = n - 1; i >= 0; i--)
    {
        sum += a[i];
        if (sum <= 0)
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        if (solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}