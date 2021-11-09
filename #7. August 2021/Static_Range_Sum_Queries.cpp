//Akif Islam (__SHERLOCK__)
//Date: 2021-08-23 11:17:05
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
    ll n, q;
    cin >> n >> q;

    vector<ll> vec(n + 1);
    ll sum = 0;
    ll input;

    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        sum += input;
        vec[i] = sum;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << vec[r] - vec[l - 1] << endl;
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