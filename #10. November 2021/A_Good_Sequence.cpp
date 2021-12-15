// Date: 2021-11-13 21:32:34

// Instruction ::
// 1. Never check the editorials before trying 3 times.
// 2. Never check other solutions before passing WA on testcase 2
// 3. Do not listen to others, follow your own advice.
// 4. If you don't see any improvement before February 2021, retired from CP.
// 5. To make your family happy, you have to code.

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

    map<int, int> mp;

    ll input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        mp[input]++;
    }

    // Check
    ll answer = 0;

    for (auto item : mp)
    {
        // If excess
        if (item.first < item.second)
            answer += (item.second - item.first);
        // Else
        else if(item.first>item.second)
            answer += item.second;
    }
    cout << answer << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}