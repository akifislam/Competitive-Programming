//Akif Islam (__SHERLOCK__)
//Date: 2021-07-31 12:15:26

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

    ll pieces = N % 6;
    ll last_pizza = 0;

    if (pieces > 4)
        last_pizza = 15; // Need for 6 Slices

    else if (pieces > 2)
    {
        last_pizza = 10; //Last Pizza of 10 Slices
    }
    else if (pieces > 0)
    {
        last_pizza = 5;
    }

    if (N < 6)
        cout << 15 << endl;
    else cout<<(N/6)*15 + last_pizza <<endl;
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