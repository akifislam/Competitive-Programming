//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-25 12:37:56

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

int main()
{

    string str;
    stack<char> stk;

    cin >> str;


    int SIZE = str.length();

    for (int i = 0; i < SIZE; i++)
    {
        if (!stk.empty() && stk.top() == str[i])
            stk.pop();

        else
            stk.push(str[i]);
    }

    string ans = "";
    while (!stk.empty())
    {
        ans.pb(stk.top());
        stk.pop();
    }

    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}