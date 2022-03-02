//Akif Islam (__SHERLOCK__)
//Date: 2021-08-12 08:09:00
// Ask Less, Practise More :)


// Is there any way to make it simpler?

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
    int no_of_candidates, no_of_cities;
    cin >> no_of_candidates >> no_of_cities;

    map<int, int> countWin;

    for (int i = 0; i < no_of_cities; i++)
    {
        vector<int> votes(no_of_candidates);

        for (int j = 0; j < no_of_candidates; j++)
        {
            cin >> votes[j];
        }

        int max_vote = *max_element(All(votes));
        for (int j = 0; j < no_of_candidates; j++)
        {
            if (votes[j] == max_vote)
            {
                countWin[j + 1]++;
                break;
            }
        }
    }

    int gotVote = 0;
    int ans = 0;

    for (auto x : countWin)
    {
        if (x.second > gotVote)
        {
            ans = x.first;
            gotVote = x.second;
        }
    }
    cout << ans << endl;
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