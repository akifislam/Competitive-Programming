//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-26 00:53:24

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

void printQueue(deque<int> D, deque<int> D2, bool rev)
{
    cout << "--QQ--" << endl;
    while (!D.empty())
    {
        cout << D.front() << " ";
        D.pop_front();
    }
    cout << endl;

    while (!D2.empty())
    {
        cout << D2.front() << " ";
        D2.pop_front();
    }
    cout << endl;
    cout << "Rev : " << rev << endl;
    cout << "--QQ--" << endl;
}

void solve()
{
    ll N;
    cin >> N;

    deque<int> dq;
    deque<int> reverse_dq;

    string command;
    int value;
    bool reverse = false;

    while (N--)
    {
        cin >> command;

        if (command == "toFront" || command == "push_back")
        {
            cin >> value;
            // cout << "Value Taken : " << value << endl;
            if (command == "toFront")
            {
                if (reverse)
                {
                    dq.push_back(value);
                    reverse_dq.push_front(value);
                }
                else
                {
                    dq.push_front(value);
                    reverse_dq.push_back(value);
                }
            }

            else
            {
                if (reverse)
                {
                    dq.push_front(value);
                    reverse_dq.push_back(value);
                }
                else
                {
                    dq.push_back(value);
                    reverse_dq.push_front(value);
                }
            }
        }

        else
        {
            if (command == "reverse")
            {
                if (reverse)
                    reverse = false;
                else
                    reverse = true;
            }
            else if (command == "front")
            {
                if (dq.empty())
                {
                    cout << "No job for Ada?" << endl;
                    continue;
                }
                if (reverse)
                {
                    cout << dq.back() << endl;
                    dq.pop_back();
                    reverse_dq.pop_front();
                }
                else
                {
                    cout << dq.front() << endl;
                    dq.pop_front();
                    reverse_dq.pop_back();
                }
            }
            else if (command == "back")
            {
                if (dq.empty())
                {
                    cout << "No job for Ada?" << endl;
                    continue;
                }

                if (reverse)
                {
                    cout << dq.front() << endl;
                    dq.pop_front();
                    reverse_dq.pop_back();
                }
                else
                {
                    cout << dq.back() << endl;
                    dq.pop_back();
                    reverse_dq.pop_front();
                }
            }
        }
        // printQueue(dq, reverse_dq, reverse);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}