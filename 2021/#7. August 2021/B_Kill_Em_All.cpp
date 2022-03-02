//Akif Islam (__SHERLOCK__)
//Date: 2021-08-20 11:49:16
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
    int input;
    int n, r;
    cin >> n >> r;

    set<int> pos;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        pos.insert(input);
    }

    int answer = 0;
    int displacement = 0;

    for (auto it = pos.rbegin(); it != pos.rend(); it++)
    {
        if (*it - displacement <= 0)
            continue;
        answer++;
        displacement += r;
    }

    cout << answer << endl;
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