//Akif Islam (__SHERLOCK__)
//Date: 2021-08-20 16:25:16
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

int check(char ch)
{
    if (ch <= '9')
        return 0; //Digit
    else if (ch <= 'Z')
        return 1; //UPPER
    else
        return 2;
}

void solve()
{
    string str;
    cin >> str;

    int freq[3], len;
    char replacedWith[] = {'0', 'X', 'x'};
    len = str.size();

    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < len; i++)
    {
        freq[check(str[i])]++;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; !freq[i]; j++)
        {
            if (freq[check(str[j])] > 1)
            {
                str[j] = replacedWith[i];
                freq[i] = 1;
            }
        }
    }
    cout<<str<<endl;
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