// Date: 2021-11-25 20:47:34

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
    ll x, y;
    cin >> x >> y;

    ll a, b;

    a = max(x, y);
    b = min(x, y);

    if (a == 0 || b == 0)
    {
        cout << 0 << endl;
        return;
    }

    ll answer_1 = 0;
    ll answer_2 = 0;

    // Prothome 3 joner team, erpore 2 jon.
    ll temp_a = a;
    ll temp_b = b;

    ll team1 = min(temp_a / 3, temp_b); // 2
    answer_1 += team1;
    temp_a -= team1 * 3;
    temp_b -= team1;

    ll team2 = min(temp_a / 2, temp_b / 2);
    answer_1 += team2;

    // cout << "ans 1 : " << answer_1 << endl;
    //----

    // Prothome 2 joner team, erpore 3 jon.
    temp_a = a;
    temp_b = b;

    team2 = min(temp_a / 2, temp_b / 2);
    answer_2 += team2;

    temp_a -= team2 * 2;
    temp_b -= team2 * 2;

    team1 = min(temp_a / 3, temp_b); // 2
    answer_2 += team1;

    // cout << "ans 2 : " << answer_2 << endl;
    //----

    cout << max(answer_1, answer_2) << endl;
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