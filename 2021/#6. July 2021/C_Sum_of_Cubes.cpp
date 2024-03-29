//Akif Islam (__SHERLOCK__)
//Date: 2021-07-18 20:37:34

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

vector<ll> cubes;

void solve()
{
    ll N;
    cin >> N;

    ll SIZE = cubes.size();

    for (ll i = 0; i < SIZE; i++)
    {
        if (binary_search(All(cubes), N - cubes[i]))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //Preprocessing
    for (ll i = 1; i * i * i <= 1e12; i++)
    {
        cubes.pb(i * i * i);
    }
    // cout << cubes.size() << endl;
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}