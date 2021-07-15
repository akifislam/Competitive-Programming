#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve()
{
    ll N;
    cin >> N;

    ll sum = 0;
    ll i = 1;
    ll count = 0;

    while (sum < N)
    {
        sum += i;
        i += 2;
        count++;
    }
    cout << count << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}