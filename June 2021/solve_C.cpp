#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define NINF INT_MIN
#define ll long long
#define ull unsigned ll
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vll vector<long long>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back

//ienjoyCP!!

const ll M = 1e9 + 7;

void solve()
{

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    if (n == 2)
    {
        for (int e : a)
            cout << e << ' ';
        cout << '\n';
        return;
    }

    int minDiff = INF;

    for (int i = 1; i < n; i++)
    {
        minDiff = min(minDiff, a[i] - a[i - 1]);
    }
    cout << minDiff << endl;
    // 1 2 2 4
    // vpii ends;

    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] == minDiff)
        {
            for (int j = i; j < n; j++)
                cout << a[j] << ' ';
            for (int j = 0; j < i; j++)
                cout << a[j] << ' ';

            break;
        }
    }

    cout << '\n';
}

int main()
{

#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}