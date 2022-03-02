//Akif Islam (__SHERLOCK__)
//Date: 2021-08-23 06:42:37
// Ask Less, Practise More :)

#include <bits/stdc++.h>
#define inf 1e5
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

const int N = 2e5;

int mn[4 * N];
int a[N];

//Segment Tree - Build with Farhan
void build(int l, int r, int node)
{
    if (l == r)
    {
        mn[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(l, mid, 2 * node);         //Left Child
    build(mid + 1, r, 2 * node + 1); //Right Child
    mn[node] = min(mn[2 * node], mn[2 * node + 1]);
    return;
}

int get(int l, int r, int node, int x, int y)
{
    // If Searching Segment ta L-R er Baire thake
    if (y < l || r < x)
        return inf;
    // If Searching Segment and L-R Ekdom Mile Jay :)
    if (x <= l && y >= r)
        return mn[node];

    int mid = (l + r) / 2;

    return min(get(l, mid, 2 * node, x, y), get(mid + 1, r, 2 * node + 1, x, y));
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, n, 1);

    cout << mn[4] << endl;
    cout<<get(1,n,1,4,7);
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