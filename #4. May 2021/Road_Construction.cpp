//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-05 13:35:29

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
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

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifdef AKIF
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')' << ':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ll long long
#define lll __int128_t
#define pb push_back
#define mp make_pair
#define All(x) (x).begin(), (x).end()
#define sz(z) (int)((z).size())
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
mt19937 rng((uint_fast32_t)chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;

class UnionFind
{
private:
    vector<int> p, rank;

public:
    UnionFind(int N)
    {
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
};
int no_of_nodes, no_of_edges;

vector<vector<int>> graph(10);
vector<vector<int>> MST;

void Kruskals()
{
    //1st : Sort wrt to Weight
    sort(graph.begin(), graph.end());

    //Take a free MST Node List with DSUw
    UnionFind *dsu = new UnionFind(no_of_nodes);

    //Edge Count will track how many edges are checked
    //MST edge count will check how many edges are drawn for MST
    int edgeCount = 0, MSTedgeCount = 0;

    while (MSTedgeCount < no_of_nodes - 1 && edgeCount < no_of_edges)
    {
        int s1 = dsu->findSet(graph[edgeCount][1]);
        int s2 = dsu->findSet(graph[edgeCount][2]);

        if (s1 == s2)
        {
            edgeCount++;
            continue;
        }
        else
        {
            dsu->unionSet(s1, s2);
            MST.push_back({graph[edgeCount][1], graph[edgeCount][2], graph[edgeCount][0]});
            edgeCount++;
            MSTedgeCount++;
        }
    }
}

void solve()
{
    cin >> no_of_edges;

    graph.resize(no_of_nodes);
    graph.clear();
    for (int i = 0; i < no_of_edges; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph.push_back({weight, from, to});
        graph.push_back({weight, to, from});
    }
    Kruskals();

    //Printing MST
    for (int i = 0; i < MST.size(); i++)
    {
        cout<<MST[i][0]<<" "<<MST[i][1]<<" "<<MST[i][2]<<endl;
    }
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
