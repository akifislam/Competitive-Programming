#include <bits/stdc++.h>
using namespace std;

#include <cmath>
#include <algorithm>

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, i, j;
        cin >> n >> m;

        int a[n][m];
        int b[n][m];
        int vis[n][m];

        memset(b, 0, sizeof(b));
        memset(vis, 0, sizeof(vis));

        vector<pair<int, pair<int, int>>> v(n * m);
        int c = 0;

        for (i = 0; i < n; i = i + 1)
        {
            for (j = 0; j < m; j = j + 1)
            {
                cin >> a[i][j];

                v[c].first = a[i][j];
                v[c].second.first = i;
                v[c].second.second = j;
                c++;
            }
        }

        sort(v.begin(), v.end());

        int x, y, k;

        for (i = 0; i < m; i = i + 1)
        {
            x = v[i].second.first;
            y = v[i].second.second;

            b[x][i] = v[i].first;

            vis[x][y] = 1;

            //cout<<x<<" "<<y<<endl;
        }

        vector<int> vx;

        for (i = 0; i < n; i = i + 1)
        {
            for (j = 0; j < m; j = j + 1)
            {
                if (vis[i][j] == 0)
                {
                    vx.push_back(a[i][j]);
                    //                    cout<<a[i][j]<<endl;
                }
            }
        }

        c = 0;

        for (i = 0; i < n; i = i + 1)
        {
            for (j = 0; j < m; j = j + 1)
            {
                if (b[i][j] != 0)
                {
                    cout << b[i][j] << " ";
                }

                else
                {
                    cout << vx[c] << " ";
                    c++;
                }
            }

            cout << endl;
        }
    }
}