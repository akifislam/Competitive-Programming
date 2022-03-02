//Akif Islam (__SHERLOCK__)
//Date: 2021-07-18 23:46:04

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
    string a;
    string b;
    cin >> a >> b;
    //If they are same, no uncommon sequence
    if (a == b)
        cout << -1 << endl;
    else
    {
        //One String can not be a subsequence of another.
        // Supopse, Cat and Caat.
        // Cat has no subseq "Caat"
        // So the answer is the maximum
        cout << max(a.length(), b.length()) << endl;
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