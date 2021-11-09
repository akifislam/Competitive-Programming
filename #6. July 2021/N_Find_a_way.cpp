//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-04 12:02:37

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#define All(x) (x).begin(), (x).end()
#define INF 0x7fffffff
int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};
vector<pair<int, int>> pos_KFC;
char arr[202][202];
int dist_Yifenfei[202][202];
int dist_Merceki[202][202];
bool visited_M[202][202];
bool visited_Y[202][202];
int n, m;

void BOMB()
{

    memset(visited_M, 0, sizeof(visited_M));
    memset(visited_Y, 0, sizeof(visited_Y));

    memset(dist_Yifenfei, -1, sizeof(dist_Yifenfei));
    memset(dist_Merceki, -1, sizeof(dist_Merceki));
    pos_KFC.clear();
}

bool isValidYifenfei(int i, int j)
{
    if (i >= 1 && i <= n && j >= 1 && j <= m && arr[i][j] != '#' && !visited_Y[i][j])
        return true;
    return false;
}

bool isValidMerceki(int i, int j)
{
    if (i >= 1 && i <= n && j >= 1 && j <= m && arr[i][j] != '#' && !visited_M[i][j])
        return true;
    return false;
}
void BFS_Yifenfei(int src_i, int src_j)
{
    dist_Yifenfei[src_i][src_j] = 0;
    visited_Y[src_i][src_j] = true;
    queue<pair<int, int>> Q;
    Q.push({src_i, src_j});

    while (!Q.empty())
    {
        auto x = Q.front();
        Q.pop();

        int cur_i = x.first;
        int cur_j = x.second;

        for (int xx = 0; xx < 4; xx++)
        {
            int new_i = cur_i + dx[xx];
            int new_j = cur_j + dy[xx];

            if (isValidYifenfei(new_i, new_j))
            {
                Q.push({new_i, new_j});
                visited_Y[new_i][new_j] = true;
                dist_Yifenfei[new_i][new_j] = dist_Yifenfei[cur_i][cur_j] + 1;
            }
        }
    }
}
void BFS_Merceki(int src_i, int src_j)
{
    visited_M[src_i][src_j] = true;

    dist_Merceki[src_i][src_j] = 0;
    queue<pair<int, int>> Q;
    Q.push({src_i, src_j});

    while (!Q.empty())
    {
        auto x = Q.front();
        Q.pop();

        int cur_i = x.first;
        int cur_j = x.second;

        for (int xx = 0; xx < 4; xx++)
        {
            int new_i = cur_i + dx[xx];
            int new_j = cur_j + dy[xx];

            if (isValidMerceki(new_i, new_j))
            {
                visited_M[new_i][new_j] = true;
                Q.push({new_i, new_j});
                dist_Merceki[new_i][new_j] = dist_Merceki[cur_i][cur_j] + 1;
            }
        }
    }
}

void solve(int n, int m)
{
    BOMB();

    vector<pair<int, int>> pos_src(2);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'Y')
            {
                pos_src[0].first = i;
                pos_src[0].second = j;
            }
            if (arr[i][j] == 'M')
            {
                pos_src[1].first = i;
                pos_src[1].second = j;
            }
            if (arr[i][j] == '@')
            {
                pos_KFC.push_back(make_pair(i, j));
            }
        }
    }

   
    
    // memset(dist_Yifenfei, -1, sizeof(dist_Yifenfei));
    BFS_Yifenfei(pos_src[0].first, pos_src[0].second);

    // memset(dist_Merceki, -1, sizeof(dist_Merceki));
    BFS_Merceki(pos_src[1].first, pos_src[1].second);


    //Print Test
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout<<dist_Merceki[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
    
    int min_cost = INF;

    for (int i = 0; i < pos_KFC.size(); i++)
    {
        int dist_from_Y = dist_Yifenfei[pos_KFC[i].first][pos_KFC[i].second];
        int dist_from_M = dist_Merceki[pos_KFC[i].first][pos_KFC[i].second];

        if (dist_from_Y != -1 && dist_from_M != -1)
            min_cost = min(min_cost, (dist_from_M + dist_from_Y));
    }
    cout << min_cost*11 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    while (cin >> n >> m)
    {
        solve(n, m);
    }
    return 0;
}