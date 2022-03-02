//Akif Islam (__SHERLOCK__)
//Date: 2021-06-11 11:57:03

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

int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};

int m, n;
char arr[1001][1001];
int dist[1001][1001];
vector<pair<int, int>> monsters;
int A_i, A_j;
int boundary_x = -1, boundary_y = -1, boundary_value = 50000;

string shortest_Path;

bool isValidforShortestPath(int i, int j)
{
    if (i >= 0 && i < m && j >= 0 && j < n)
        return true;
    else
        return false;
}

void finding_shortest_path(int x, int y)
{
    if (x == boundary_x && y == boundary_y)
        return;

    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (!isValidforShortestPath(new_x, new_y))
            continue;

        if (dist[new_x][new_y] == dist[x][y] - 1)
        {
            char move;
            // cout << "Here" << endl;
            if (dx[i] == 0 && dy[i] == 1)
                move = 'R';
            if (dx[i] == 0 && dy[i] == -1)
                move = 'L';
            if (dx[i] == -1 && dy[i] == 0)
                move = 'U';
            if (dx[i] == 1 && dy[i] == 0)
                move = 'D';
            shortest_Path.pb(move);
            finding_shortest_path(new_x, new_y);
            break;
        }
    }
}

bool isValid(int i, int j)
{
    if (((i >= 0 && i < m) && (j >= 0 && j < n)) && arr[i][j] == '.' && dist[i][j] == -1)
        return true;
    else
        return false;
}
bool isValidMonster(int i, int j)
{
    if (((i >= 0 && i < m) && (j >= 0 && j < n)) && arr[i][j] != '#' && dist[i][j] == -1)
        return true;
    else
        return false;
}

void BFS(int i, int j)
{
    dist[i][j] = 0;
    queue<pair<int, int>> Q;
    Q.push({i, j});

    while (!Q.empty())
    {
        int x = Q.front().first;  //i
        int y = Q.front().second; //j
        // cout << arr[x][y] << endl;
        Q.pop();

        for (int q = 0; q < 4; q++)
        {
            int cur_i = x + dx[q];
            int cur_j = y + dy[q];
            // cout << "Checking : " << cur_i << " " <<cur_j << endl;

            if (isValid(cur_i, cur_j))
            {
                dist[cur_i][cur_j] = dist[x][y] + 1;
                Q.push({cur_i, cur_j});
            }
        }
    }
}

void BFS_Monster(int i, int j)
{
    dist[i][j] = 0;
    queue<pair<int, int>> Q;
    Q.push({i, j});

    while (!Q.empty())
    {
        int x = Q.front().first;  //i
        int y = Q.front().second; //j
        // cout << arr[x][y] << endl;
        Q.pop();

        for (int q = 0; q < 4; q++)
        {
            int cur_i = x + dx[q];
            int cur_j = y + dy[q];
            // cout << "Checking : " << cur_i << " " <<cur_j << endl;

            if (isValidMonster(cur_i, cur_j))
            {
                dist[cur_i][cur_j] = dist[x][y] + 1;
                Q.push({cur_i, cur_j});
            }
        }
    }
}

void solve()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'M')
                monsters.push_back(make_pair(i, j));

            if (arr[i][j] == 'A')
            {

                A_i = i;
                A_j = j;
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    BFS(A_i, A_j);

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //Founding the Boundary Point
    vector<pair<int, pair<int, int>>> boundaries;

    //Checking First and Last Column

    for (int i = 0; i < m; i++)
    {
        if (dist[i][0] != -1)
            boundaries.push_back({dist[i][0], {i, 0}});
    }

    for (int i = 0; i < m; i++)
    {
        if (dist[i][n - 1] != -1)
            boundaries.push_back({dist[i][n - 1], {i, n - 1}});
    }

    //Checking First and Last Row
    for (int i = 1; i < n - 1; i++)
    {
        if (dist[0][i] != -1)
            boundaries.push_back({dist[0][i], {0, i}});
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (dist[m - 1][i] != -1)
            boundaries.push_back({dist[m - 1][i], {m - 1, i}});
    }

    sort(All(boundaries));

    bool Possible = false;
    for (int i = 0; i < boundaries.size() && !Possible; i++)
    {
        boundary_x = boundaries[i].second.first;
        boundary_y = boundaries[i].second.second;

        // cout << "Escape Point : " << boundary_x << " " << boundary_y << endl;

        memset(dist, -1, sizeof(dist));
        BFS_Monster(boundary_x, boundary_y);

        Possible = true;

        for (int i = 0; i < monsters.size(); i++)
        {
            if (dist[A_i][A_j] >= dist[monsters[i].first][monsters[i].second] && dist[monsters[i].first][monsters[i].second] != -1)
            {
                // cout << "Monster Eaten ! " << endl;
                Possible = false;
                break;
            }
        }
    }

    //So, Now BFS from here

    //Print
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //Check if monster can reach

    if (!Possible)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        finding_shortest_path(A_i, A_j);
        // reverse(All(shortest_Path));
        cout << shortest_Path.size() << endl;

        for (auto x : shortest_Path)
        {
            cout << x;
        }
        cout << endl;
    }
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