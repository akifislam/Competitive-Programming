//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-03-08 13:08:26

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

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << gap << p.second << ')';
}

#define ll long long
#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n;
int arr[101];
bool visited[101];

int search(int start, int end)
{
    int maxi = -1;
    int maxi_index = -1;
    for (int i = start; i <=end; i++)
    {
        if(arr[i]>maxi) {
            maxi = arr[i];
            maxi_index = i;
        }
    }
    visited[maxi_index]= true;

    return maxi;
    
}

void solve()
{
    cin >> n;
    vector<int> treeLevel[n];

    memset(visited, 0, sizeof(visited));
    int maximum = -1;
    int maxi_index = -1;
    int level = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i]>maximum) {
            maximum = arr[i];
            maxi_index = i;
        }
    }

    treeLevel[level].pb(maximum);
    visited[maxi_index] = true;
    level++;

    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}