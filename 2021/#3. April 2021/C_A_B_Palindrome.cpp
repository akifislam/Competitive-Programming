//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-10 21:24:29

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

void solve()
{
    int no_of_zero, no_of_one;
    cin >> no_of_zero >> no_of_one;

    string str;
    cin >> str;

    //Check
    bool no_question = true;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]=='?'){
            no_question = false;
            break;
        }
    }
    if(no_question){
        cout<<str<<endl;
        return;
    }
    
    

    bool isPossible = true;

    //If One is Zero, Possible
    if (no_of_zero == 0 || no_of_one == 0)
    {
        //Kono 1 Thaka Jabena
        if (no_of_zero > 0)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '1')
                {
                    isPossible = false;
                    break;
                }
            }
            if (!isPossible)
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                for (int i = 0; i < str.length(); i++)
                {
                    cout << '0';
                }
                cout << endl;
                return;
            }
        }

        if (no_of_one > 0)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '0')
                {
                    isPossible = false;
                    break;
                }
            }
            if (!isPossible)
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                for (int i = 0; i < str.length(); i++)
                {
                    cout << '1';
                }
                cout << endl;
                return;
            }
        }
    }

    //Odd Odd Not Possible
    if (no_of_one % 2 == 1 && no_of_zero % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }

    // Even Even

    // Odd Even
    //Welcome

    //Check
    int n = no_of_zero + no_of_one;
    int temp_0 = no_of_zero;
    int temp_1 = no_of_one;

    if (n % 2 == 0)
    {
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            if (str[i] != '?' || str[j] != '?')
            {
                if (str[i] != '?')
                {
                    str[j] = str[i];
                    if (str[j] == '0')
                        temp_0 -= 2;
                    else
                        temp_1 -= 2;
                }
                else
                {
                    str[i] = str[j];
                    if (str[j] == '0')
                        temp_0 -= 2;
                    else
                        temp_1 -= 2;
                }
            }
            // Both '?'
            else
            {
                if (temp_1 > temp_0)
                {
                    str[i] = str[j] = '1';
                    temp_1 -= 2;
                }
                else
                {
                    str[i] = str[j] = '0';
                    temp_0 -= 2;
                }
            }
        }

        string rev = str;
        reverse(rev.begin(), rev.end());
        if (rev == str)
            cout << str << endl;
        else
            cout << -1 << endl;
    }

    // For Odd Even
    if (n % 2 == 1)
    {
        if (str[n / 2] == '1')
        {
            temp_1--;
        }
        else if (str[n / 2] == '0')
            temp_0--;
        else if (str[n / 2] == '?')
        {
            if (temp_1 % 2 == 1)
                str[n / 2] = '1', temp_1--;
            else
                str[n / 2] = '0', temp_0--;
        }

        for (int i = 0, j = n - 1; i < n / 2 && i < j; i++, j--)
        {
            if (str[i] != '?' || str[j] != '?')
            {
                if (str[i] != '?')
                {
                    str[j] = str[i];
                    if (str[j] == '0')
                        temp_0 -= 2;
                    else
                        temp_1 -= 2;
                }
                else
                {
                    str[i] = str[j];
                    if (str[j] == '0')
                        temp_0 -= 2;
                    else
                        temp_1 -= 2;
                }
            }
            // Both '?'
            else
            {
                if (temp_1 > temp_0)
                {
                    str[i] = str[j] = '1';
                    temp_1 -= 2;
                }
                else
                {
                    str[i] = str[j] = '0';
                    temp_0 -= 2;
                }
            }
        }

        string rev = str;
        reverse(rev.begin(), rev.end());
        if (rev == str)
            cout << str << endl;
        else
            cout << -1 << endl;
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