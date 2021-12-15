// Date: 2021-11-25 20:39:19

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

bool isEven(char x)
{
    if (x == '2' || x == '4' || x == '6' || x == '8')
        return true;
    else
        return false;
}

void solve()
{
    string str;
    cin >> str;

    int SIZE = str.length();
    if (isEven(str[SIZE - 1]))
        cout << 0 << endl;
    else if (isEven(str[0]))
        cout << 1 << endl;
    else
    {
        bool hasEven = false;
        for (int i = 0; i < SIZE; i++)
        {
            if (isEven(str[i]))
            {
                hasEven = true;
                break;
            }
        }
        if (hasEven)
            cout << 2 << endl;
        else
            cout << -1 << endl;
    }
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