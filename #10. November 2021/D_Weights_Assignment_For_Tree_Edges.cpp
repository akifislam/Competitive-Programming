#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> par(n + 1), per(n + 1);

    int root;
    for (int i = 1; i <= n; i++)
    {
        cin >> par[i];
        if (par[i] == i)
            root = i;
    }

    for (int i = 1; i <= n; i++)
        cin >> per[i];

    vector<int> dist(n + 1, -1);

    vector<int> w(n + 1);

    dist[root] = 0;

    if (per[1] != root)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 2; i <= n; i++)
    {

        int node = per[i];
        int p = par[node];

        cout << "Node : " << node << endl;
        cout << " P : " << p << endl;

        if (dist[p] == -1)
        {
            cout << -1 << endl;
            return;
        }

        dist[node] = i - 1;
        w[node] = dist[node] - dist[p];
    }

    for (int i = 1; i <= n; i++)
        cout << w[i] << ' ';
    cout << endl;
}
int32_t main()
{
    // FAST;
    int t = 1;
    cin >> t;
    /*
    fact[0] = 1;
    for(int i = 1;i<M;i++)
        fact[i] = (i * fact[i-1])%mod;
        */
    int test = 1;
    while (t--)
    {
        //	cout << "Case #" << test << ": ";
        solve();
        test++;
    }
}