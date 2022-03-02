//Akif Islam (__SHERLOCK__)
//Date: 2021-08-12 16:03:03
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
    map<char, int> weight;
    for (int i = 0; i < 3; i++)
    {
        string str;
        cin >> str;

        if (str[1] == '>')
        {
            weight[str[0]]++;
            weight[str[2]]--;
        }

        else
        {
            weight[str[0]]--;
            weight[str[2]]++;
        }
    }

    //Check
    set<pair<int, char>> seq;
    set<int> checker;

    for (auto x : weight)
    {
        seq.insert(make_pair(x.second, x.first));
        checker.insert(x.second);
    }

    if (checker.size() != 3)
        cout << "Impossible" << endl;
    else
    {
        // cout << "Size : " << seq.size() << endl;
        for (auto item : seq)
        {
            cout << item.second;
        }
        cout << endl;
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