//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-05-23 17:40:09

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

ll factorial(ll x)
{
    if (x == 0)
        return 1.0000;
    else
        return (x * factorial(x - 1.000));
}

void solve()
{
    string Drazil;
    string Dreamoon;

    cin >> Drazil;
    cin >> Dreamoon;

    //Checking Total Value of Input String
    //By Drazil

    int count_drazil = 0;
    for (int i = 0; i < Drazil.size(); i++)
    {
        if (Drazil[i] == '+')
            count_drazil++;
        else
            count_drazil--;
    }
    // cout << "Total Drazil Point : " << count_drazil << endl;

    //Checking Current Point of Dreamon
    int count_dreamoon = 0, hold = 0;

    for (int i = 0; i < Dreamoon.size(); i++)
    {
        if (Dreamoon[i] == '+')
            count_dreamoon++;
        else if (Dreamoon[i] == '-')
            count_dreamoon--;
        else
            hold++;
    }

    // cout << "Total Dreamoon Point : " << count_dreamoon << endl;

    long double answer = 0.000000;

    // If No ?, then Drazil == Dreamoon hote hobe
    if (hold == 0)
    {
        if (count_dreamoon != count_drazil)
            cout << "0.000000000000" << endl;
        else
            cout << "1.000000000000" << endl;
    }

    else
    {
        // Milanor Try Kori
        int plus, minus;
        plus = 0, minus = 0;

        for (int i = 0; i < Dreamoon.size(); i++)
        {
            if (Dreamoon[i] == '?')
            {
                if (count_drazil > count_dreamoon)
                {
                    Dreamoon[i] = '+';
                    count_dreamoon++;
                    plus++;
                }
                else
                {
                    Dreamoon[i] = '-';
                    count_dreamoon--;
                    minus++;
                }
            }
        }

        if (count_dreamoon == count_drazil)
        {
            answer = (factorial(hold) / (factorial(plus) * factorial(minus))) / pow(2, hold);
            printf("%.12Lf\n", answer);
        }
        else
        {
            cout << "0.000000000000" << endl;
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
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}