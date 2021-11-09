//Akif Islam (__SHERLOCK__)
//Date: 2021-08-22 13:03:40
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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll N;
vector<pair<ii, int>> classtime;

bool isIntersect(int x)
{
    int prev_end = -1;
    for (int i = 0; i < N; i++)
    {
        //Canceling x-th row
        if (classtime[i].second == x)
            continue;
        //Not Overlapping
        if (prev_end <= classtime[i].first.second)
        {
            prev_end = classtime[i].first.first;
            continue;
        }
        else
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    cin >> N;

    int start;
    int end;

    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;
        classtime.push_back({{end, start}, i + 1});
    }

    sort(classtime.begin(), classtime.end());

    //Check
    vector<int> answer;

    for (int i = 0; i < N; i++)
    {
        if (!isIntersect(classtime[i].second))
            answer.push_back(classtime[i].second);
    }

    cout << answer.size() << endl;
    sort(All(answer));
    
    for (auto x : answer)
    {
        cout << x << " ";
    }
    cout << endl;
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