//Akif Islam (__SHERLOCK__)
//Date: 2021-06-06 11:46:48

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

class UnionFind
{
public:
    vector<int> p, rank;
    int N;

public:
    UnionFind(int N)
    {
        this->N = N;
        rank.assign(N, 0);
        p.resize(N);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int s)
    {
        return (p[s] == s) ? s : p[s] = findSet(p[s]);
    }
    bool isSameSet(int a, int b)
    {
        return findSet(a) == findSet(b);
    }
    bool unionSet(int a, int b)
    {
        if (!isSameSet(a, b))
        {
            int x = findSet(a);
            int y = findSet(b);

            if (rank[x] > rank[y])
            {
                p[y] = x;
            }
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
            return true;
        }
        else
            return false;
    }

    void printDSU()
    {
        for (int i = 1; i < N; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }

    vector<int> printCycle(int x)
    {
        int m = findSet(x);
        vector<int> cycle;
        for (int i = 1; i < N; i++)
        {
            if (p[i] == m)
                cycle.push_back(i);
        }
        cycle.push_back(cycle[0]);
        return cycle;
    }
};

void solve()
{
    // memset(dsu,0,sizeof(dsu));

    int n, m;
    cin >> n >> m;
    UnionFind *u = new UnionFind(6);

    int from, to;
    bool hasCycle = false;

    vector<int> cycle;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        if (!u->unionSet(from, to) && !hasCycle)
        {
            hasCycle = true;
            cycle = u->printCycle(to);
        }
    }

    if (!hasCycle)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << cycle.size() << endl;
        for (int i = 0; i < cycle.size(); i++)
        {
            cout << cycle[i] << " ";
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