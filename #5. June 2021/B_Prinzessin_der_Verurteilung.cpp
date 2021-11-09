//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-06-06 21:23:58

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

int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};

//Pigeon Hole Principal
map<string, int> words;

void loadGun(int size)
{
    words.clear();
    if (size == 1)
    {
        for (int i = 97; i < 123; i++)
        {
            string new_string;
            new_string.pb((char)i);
            words[new_string] = 0;
        }
    }
    if (size == 2)
    {
        for (int i = 97; i < 123; i++)
        {
            for (int j = 97; j < 123; j++)
            {
                string new_string;
                new_string.pb((char)i);
                new_string.pb((char)j);
                words[new_string] = 0;
            }
        }
    }
    if (size == 3)
    {
        for (int i = 97; i < 123; i++)
        {
            for (int j = 97; j < 123; j++)
            {
                string new_string = "a";
                new_string.pb((char)i);
                new_string.pb((char)j);
                words[new_string] = 0;
            }
        }
        words["baa"] = 0;
    }
}

void solve()
{
    int N;
    cin >> N;
    string str;
    cin >> str;

    bool hasFound = false;
    int size = 0;
    while (!hasFound && size < 4)
    {
        size++;
        loadGun(size);

        for (int i = 0; i < N; i++)
        {
            words[str.substr(i, size)]++;
        }

        for (auto m : words)
        {
            if (m.second == 0)
            {
                hasFound = true;
                cout << m.first << endl;
                break;
            }
        }
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