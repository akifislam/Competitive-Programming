/******************************************************************************

                         بسم الله الرحمن الرحيم
                     Author: Mst: Mhamuda Khatun
                               RUCSE27

*******************************************************************************/

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
#define yes cout << "YES" \
                 << "\n"
#define no cout << "NO" \
                << "\n"
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
char dz[] = {'U', 'D', 'R', 'L'};
ll n, m;

vector<pair<ll, ll>> path;
map<pair<ll, ll>, pair<ll, ll>> mp;
char graph[MAX][MAX], x[MAX][MAX];
bool validPath[MAX][MAX];
ll distance_A_to_boundary[MAX][MAX], distance_boundary_to_AM[MAX][MAX];
vector<pair<ll, pair<ll, ll>>> boundary;

bool valid_J(ll u, ll v)
{
    if (u >= 0 && u < n && v >= 0 && v < m && graph[u][v] == '.' && distance_A_to_boundary[u][v] == -1)
        return true;
    else
        return false;
}

bool valid_F(ll u, ll v)
{
    if (u >= 0 && u < n && v >= 0 && v < m && graph[u][v] != '#' && distance_boundary_to_AM[u][v] == -1)
        return true;
    else
        return false;
}

bool valid_path(ll u, ll v)
{
    if (u >= 0 && u < n && v >= 0 && v < m && graph[u][v] == '.' && !validPath[u][v])
        return true;
    else
        return false;
}

bool BFS_Bounday_Check(ll src_r, ll src_c)
{
    bool flag = false;
    queue<pair<ll, ll>> Q;
    Q.push({src_r, src_c});
    distance_A_to_boundary[src_r][src_c] = 0;

    while (!Q.empty())
    {
        pair<ll, ll> cur = Q.front();
        Q.pop();

        ll cur_r = cur.first;
        ll cur_c = cur.second;

        for (int i = 0; i < 4; i++)
        {
            ll u = cur_r + dx[i];
            ll v = cur_c + dy[i];

            if (valid_J(u, v))
            {
                distance_A_to_boundary[u][v] = distance_A_to_boundary[cur_r][cur_c] + 1;
                Q.push({u, v});

                if (u == 0 || u == n - 1 || v == 0 || v == m - 1)
                {
                    flag = true;
                    boundary.pb({distance_A_to_boundary[u][v], {u, v}});
                }
            }
        }
    }

    if (flag)
        return true;
    else
        return false;
}

bool BFS_Monster_Check(ll dest_r, ll dest_c)
{
    ll dist_a = LLONG_MAX, dist_m = LLONG_MAX;

    queue<pair<ll, ll>> Q;
    Q.push({dest_r, dest_c});
    distance_boundary_to_AM[dest_r][dest_c] = 0;

    while (!Q.empty())
    {
        pair<ll, ll> cur = Q.front();
        Q.pop();

        ll cur_r = cur.first;
        ll cur_c = cur.second;

        for (int i = 0; i < 4; i++)
        {
            ll u = cur_r + dx[i];
            ll v = cur_c + dy[i];

            if (valid_F(u, v))
            {
                distance_boundary_to_AM[u][v] = distance_boundary_to_AM[cur_r][cur_c] + 1;
                Q.push({u, v});

                if (graph[u][v] == 'A')
                {
                    dist_a = min(dist_a, distance_boundary_to_AM[u][v]);
                    break;
                }
                if (graph[u][v] == 'M')
                    dist_m = min(dist_m, distance_boundary_to_AM[u][v]);
            }
        }
    }
    cout<<"Dist A : "<<dist_a<<endl;
    cout<<"Dist M : "<<dist_m<<endl;
    if (dist_a < dist_m)
        return true;
    else
        return false;
}

void PATH_FROM_A_TO_BOUNDARY(ll src_r, ll src_c, ll dest_r, ll dest_c)
{
    queue<pair<ll, ll>> Q;
    validPath[src_r][src_c] = true;
    Q.push(make_pair(src_r, src_c));

    while (!Q.empty())
    {
        ll cur_r = Q.front().first;
        ll cur_c = Q.front().second;
        Q.pop();

        for (ll i = 0; i < 4; i++)
        {
            ll u = cur_r + dx[i];
            ll v = cur_c + dy[i];

            if (valid_path(u, v))
            {
                validPath[u][v] = true;
                Q.push(make_pair(u, v));
                mp[{u, v}] = {cur_r, cur_c};

                if (u == dest_r && v == dest_c)
                    break;
            }
        }
    }
}

string PATH(ll src_r, ll src_c, ll dest_r, ll dest_c)
{
    string pathdirection = "";
    path.pb({dest_r, dest_c}); // R

    ll prev_now_r = dest_r;
    ll prev_now_c = dest_c;

    while (1)
    {

        //cout<<"Source : "<<src_r<<" "<<src_c<<"\n";
        //cout<<"BEFORE PATH PRINT: "<<prev_now_r <<" "<<prev_now_c<<"\n";

        ll now_r = mp[{prev_now_r, prev_now_c}].first;
        ll now_c = mp[{prev_now_r, prev_now_c}].second;

        // cout << "AFTER PATH PRINT: " << now_r << " " << now_c << "\n";

        prev_now_r = now_r;
        prev_now_c = now_c;

        if (prev_now_r == src_r && prev_now_c == src_c)
        {
            path.pb({src_r, src_c});

            break;
        }

        path.pb({now_r, now_c});
    }

    reverse(all(path));

    for (ll i = 0; i < path.size() - 1; i++)
    {
        for (ll j = 0; j < 4; j++)
        {
            if (path[i].first + dx[j] == path[i + 1].first && path[i].second + dy[j] == path[i + 1].second)
                pathdirection += dz[j];
        }
    }

    return pathdirection;
}

int main()
{
    fastio;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //OrderSetTree ost;

    ll i, j, src_c, src_r, dest_r, dest_c;

    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            //cout<<graph[i][j];

            if (graph[i][j] == 'A')
            {
                src_r = i;
                src_c = j;
            }
        }
        //cout<<"\n";
    }

    memset(distance_A_to_boundary, -1, sizeof(distance_A_to_boundary));

    if (BFS_Bounday_Check(src_r, src_c))
    {
        sort(all(boundary));
        bool ok = false;

        // cout << boundary.size() << "\n";

        // for (i = 0; i < boundary.size(); i++)
        //     cout << "dist = " << boundary[i].first << " row = " << boundary[i].second.first << " col = " << boundary[i].second.second << "\n";
        for (i = 0; i < boundary.size(); i++)
        {
            memset(distance_boundary_to_AM, -1, sizeof(distance_boundary_to_AM));
            ll x = boundary[i].second.first;
            ll y = boundary[i].second.second;

            if (BFS_Monster_Check(x, y))
            {
                dest_r = x;
                dest_c = y;

                ok = true;
                break;
            }
        }

        //Print Path
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
                // cout << distance_boundary_to_AM[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        if (ok)
        {
            memset(validPath, false, sizeof(validPath));
            // cout << src_r << " " << src_c << " " << dest_r << " " << dest_c << endl;
            PATH_FROM_A_TO_BOUNDARY(src_r, src_c, dest_r, dest_c); //Working

            //Print Path
            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j < m; j++)
            //     {
            //         cout << validPath[i][j] << " ";
            //     }
            //     cout << endl;
            // }

            string pathdirection = PATH(src_r, src_c, dest_r, dest_c);
            yes;
            cout << pathdirection.size() << "\n";
            cout << pathdirection << "\n";
        }
        else
        {
            no;
            // cout << "Inner";
        }
    }

    else
    {
        no;
        // cout << "Outer";
    }

    cout << "\n";
    return 0; //:D
}