//Akif Islam (__SHERLOCK__)
//Date: 2021-09-12 20:56:53
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
    string str;
    cin >> str;

    ll SIZE = str.size();

    bool hasZero = false;
    bool hasOne = false;

    //Total Check
    for (int i = 0; i < SIZE && (!hasZero || !hasOne); i++)
    {
        if (!hasZero)
        {
            if (str[i] == '0')
            {
                hasZero = true;
            }
        }

        if (!hasOne)
        {
            if (str[i] == '1')
            {
                hasOne = true;
            }
        }
    }
    ll answer_1 = 0;

    if (hasZero)
    {
        if (hasOne)
            answer_1 = 2;
        else
            answer_1 = 1;
    }
    else
    {
        answer_1 = 0;
    }

    bool gotZero = false;
    ll answer_2 = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (str[i] != '0')
            gotZero = false;

        else if (str[i] == '0' && gotZero)
            continue;

        if (str[i] == '0' && !gotZero)
        {
            answer_2++;
            gotZero = true;
        }
    }

    cout << min(answer_1, answer_2) << endl;
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