#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define ull unsigned long long
#define OrderSetTree tree<ll, null_type /*mapped_type*/, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define pi 2 * acos(0.0)

#define pb push_back
#define gap ' '
#define yes cout << "YES"
#define no cout << "NO"
#define all(v) v.begin(), v.end()
#define fastio                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
#define mod 1000000007
#define MAX 1004
#define N 305

ll dx[] = {-1, +1, 0, 0};
ll dy[] = {0, 0, +1, -1};
ll n, m;

vector<pair<ll, ll>> path;
map<pair<ll, ll>, pair<ll, ll>> mp;
char graph[MAX][MAX], x[MAX][MAX];
bool visited[MAX][MAX];

bool isValid(ll u, ll v)
{
    if (u >= 0 && u < n && v >= 0 && v <= m && !visited[u][v] && graph[u][v] != '#')
        return true;
    else
        return false;
}

bool BFS(ll src_r, ll src_c, ll dest_r, ll dest_c)
{
    queue<pair<ll, ll>> Q;
    Q.push({src_r, src_c});
    visited[src_r][src_c] = true;
    mp[{src_r, src_c}] = {src_r, src_c};

    while (!Q.empty())
    {
        ll cur_r = Q.front().first;
        ll cur_c = Q.front().second;
        Q.pop();

        for (ll i = 0; i < 4; i++)
        {
            ll u = cur_r + dx[i];
            ll v = cur_r + dy[i];

            if (isValid(u, v))
            {
                visited[u][v] = true;
                Q.push({u, v});

                if (i = 0)
                    x[u][v] = 'U';
                else if (i = 1)
                    x[u][v] = 'D';
                else if (i = 2)
                    x[u][v] = 'R';
                else
                    x[u][v] = 'L';
            }
        }
    }

    if (!visited[dest_r][dest_c])
        return false;

    return true;
}

void PATH(ll src_r, ll src_c, ll dest_r, ll dest_c)
{
    path.pb({dest_r, dest_c});

    ll now_r = dest_r;
    ll now_c = dest_c;

    while (now_r != src_r && now_c != dest_c)
    {
        now_r = mp[{now_r, now_c}].first;
        now_c = mp[{now_r, now_c}].second;
        path.pb({now_r, now_c});
    }

    reverse(all(path));
}

int main()
{
    fastio;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //OrderSetTree ost;

    ll i, j, src_r, src_c, dest_r, dest_c;
    cin >> n >> m;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 'A')
            {
                src_r = i;
                src_c = j;
            }

            if (graph[i][j] == 'B')
            {
                dest_r = i;
                dest_c = j;
            }
        }
    }

    if (BFS(src_r, src_c, dest_r, dest_c))
    {
        yes;
        cout << "\n";
        PATH(src_r, src_c, dest_r, dest_c);
        cout << path.size() << "\n";

        for (i = 0; i < path.size(); i++)
            cout << x[path[i].first][path[i].second];

        //for(auto it=mp.begin();it!=mp.end();it++)
        //cout<<it->second.first<<gap<<it->second.second<<"\n";
        // Map Print by Akif
        cout << "Map Print" << endl;
        for (auto x : mp)
        {
            cout << "(" << x.first.first << "," << x.first.second << ")"
                 << "--> "
                 << "(" << x.second.first << "," << x.second.second << ")" << endl;
        }
        //
    }
    else
        no;
    cout << endl;

    // Map Print by Akif
    cout << "Map Print" << endl;
    for (auto x : mp)
    {
        cout << "(" << x.first.first << "," << x.first.second << ")"
             << "--> "
             << "(" << x.second.first << "," << x.second.second << ")" << endl;
    }
    //

    cout << "\n";
    return 0; //:D
}
