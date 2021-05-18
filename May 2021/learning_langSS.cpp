//https://codeforces.com/contest/277/submission/49904405
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class DSU
{
private:
    vector<int> parent, ranks;

public:
    DSU(int n)
    {
        parent.assign(n + 1, 0);
        ranks.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return find(parent[x]);
    }
    bool isSameSet(int x, int y)
    {
        return find(x) == find(y);
    }

    void unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px != py)
        {
            if (ranks[px] > ranks[py])
                parent[py] = px;
            else
            {
                parent[px] = py;
                if (ranks[x] == ranks[y])
                    ranks[py]++;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int N, M, x, y;
    cin >> N >> M;

    vector<vector<int>> lang(M + 1);

    int zeros = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> x;
        if (x == 0)
            zeros++;
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            lang[y].push_back(i);
        }
    }

    DSU dsu(N);
    int components = N;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j < lang[i].size(); j++)
        {
            int a = lang[i][0], b = lang[i][j];
            if (dsu.isSameSet(a, b))
            {
                continue;
            }
            components--;
            dsu.unite(a, b);
        }
    }

    if (zeros == N)
        cout << N << endl;
    else
        cout << components - 1 << endl;
    return 0;
}