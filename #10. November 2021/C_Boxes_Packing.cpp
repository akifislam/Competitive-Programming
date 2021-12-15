#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

#define info(x) cerr << #x << " = " << x << endl
#define vec vector
#define ALL(x) (x).begin(), (x).end()

int const inf = 1e9;
ll const inf64 = 1e18;

void mprint(multiset<int> q)
{
    for (auto item : q)
    {
        cout << item << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), greater<int>());

    multiset<int> ms;

    for (int i = 0; i < n; i++)
    {
        if (ms.empty())
        {
            ms.insert(vec[i]);
            continue;
        }

        auto x = ms.upper_bound(vec[i]);

        if (x == ms.end())
        {
            ms.insert(vec[i]);
        }

        else
        {
            ms.erase(x);
            ms.insert(vec[i]);
        }
    }
    cout << ms.size() << endl;
}