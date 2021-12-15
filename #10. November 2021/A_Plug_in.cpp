// Date: 2021-11-15 01:34:05

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

void PQ(deque<char> Q)
{
    // Print
    while (!Q.empty())
    {
        cout << Q.front();
        Q.pop_front();
    }
    cout << endl;
    cout << "---" << endl;
}

void solve()
{

    string str;
    cin >> str;

    int SIZE = str.size();

    deque<char> Q;

    for (int i = 0; i < SIZE; i++)
    {
        // PQ(Q);
        if (Q.size() > 0 && Q.back() == str[i])
        {
            Q.pop_back();
            continue;
        }
        Q.push_back(str[i]);
    }

    // Print
    while (!Q.empty())
    {
        cout << Q.front();
        Q.pop_front();
    }
    cout << endl;
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