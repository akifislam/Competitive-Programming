//First Problem in Segment Tree

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 2e9
const ll SIZE = 2e5 + 5;

vector<ll> a;
ll mn[SIZE * 4];

void build(ll l, ll r, ll node)
{
    if (l == r)
    {
        mn[node] = a[l];
        return;
    }
    ll mid = (l + r) / 2;

    build(l, mid, 2 * node);
    build(mid + 1, r, 2 * node + 1);
    mn[node] = min(mn[2 * node], mn[2 * node + 1]);
    return;
}

ll get(ll l, ll r, ll node, ll x, ll y)
{
    if (y < l || r < x)
        return inf;

    if (x <= l && y >= r)
        return mn[node];

    ll mid = (l + r) / 2;

    ll left_child = get(l, mid, 2 * node, x, y);
    ll right_child = get(mid + 1, r, 2 * node + 1, x, y);

    return min(left_child, right_child);
}

int main()
{
    a.push_back(inf);

    ll n, q;
    cin >> n >> q;

    ll input;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back(input);
    }

    build(1, n, 1);
    
    ll left, right;
    while (q--)
    {
        cin >> left >> right;
        cout << get(1, n, 1, left, right) << endl;
    }
}