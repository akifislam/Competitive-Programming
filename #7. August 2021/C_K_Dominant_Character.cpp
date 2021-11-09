//Akif Islam (__SHERLOCK__)
//Date: 2021-08-18 06:47:40
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
    int SIZE = str.size();

    map<char, int> mp;
    char s = 'a';

    for (int i = 0; i < 26; i++)
    {
        mp[s] = 0;
        s++;
    }

    for (int i = 0; i < SIZE; i++)
    {
        mp[str[i]]++;
    }

    int k = 0;
    int prev = 0;
    int answer = SIZE;

    for (auto item : mp)
    {
        if (item.second < 2)
            continue;

        k = 0;
        prev = 0;

        for (int i = 0; i < SIZE; i++)
        {
            if (str[i] == item.first)
            {
                k = max(k, i - prev);
                prev = i;
            }
        }
        answer = min(answer, k);
        cout << "For " << item.first << ", " << k << endl;
       
    }
    cout << answer << endl;
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