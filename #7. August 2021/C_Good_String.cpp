//Learning 


//Akif Islam (__SHERLOCK__)
//Date: 2021-08-19 20:44:53
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
    int n;
    string str;
    string res;

    cin >> n;

    cin >> str;

    for (int i = 0; i < n; i++)
    {
        if (res.size() % 2 == 0 || res.back() != str[i])
            res.push_back(str[i]);
    }
    if (res.size() % 2 == 1)
        res.pop_back();

    cout << n - res.size() << endl;
    cout << res << endl;
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