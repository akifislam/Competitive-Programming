// n = 4, k = 6 ----> ceil (6/4)--2
//8 8---> 1
// 8 17 --> ceil (17/8)--3

// 99  3
//  33

//Akif Islam (__SHERLOCK__)
//Date: 2021-06-26 03:14:38

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
    ll n, k;
    cin >> n >> k;
    // 4  3
    if (n > k)
        k = k * ((n+k-1)/k);

    cout << ((k+n-1) / n) << endl;
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
