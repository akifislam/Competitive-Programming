//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-03 21:22:48

#include <bits/stdc++.h>

using namespace std;

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

void solve()
{
    int length;
    cin >> length;

    string a, b;
    cin >> a >> b;

    //1st Check
    if (a == b)
    {
        cout << "YES" << endl;
        return;
    }

    vector<int> no_of_zero;
    vector<int> no_of_one;

    no_of_zero.pb(0);
    no_of_one.pb(0);

    int c0 = 0;
    int c1 = 0;

    for (int i = 0; i < length; i++)
    {
        if (a[i] == '0')
            c0++;
        else
            c1++;
        //        printf("Count 0 : %d, Count 1 : %d\n",c0,c1);
        no_of_zero.pb(c0);
        no_of_one.pb(c1);
    }

    //Print
    for (int i = 0; i <= length; i++)
    {
        cout << no_of_zero[i] << " ";
    }

    cout << endl;
    //.....
    //Print
    for (int i = 0; i <= length; i++)
    {
        cout << no_of_one[i] << " ";
    }

    cout << endl;
    //.....

    bool same;

    if (a[0] == b[0])
    {
        same = true;
    }
    else
        same = false;

    int l = 0;
    int check0, check1;
    bool isPossible = true;

    for (int i = 0; i < length; i++)
    {
        //If Same
        if (!same)
        {
            if (a[i] == b[i])
            {
                check0 = no_of_zero[i] - no_of_zero[l];
                cout << "Got 0 : " << check0 << endl;
                check1 = no_of_zero[i] - no_of_one[l];
                cout << "Got 1 : " << check1 << endl;

                if (check0 != check1)
                {
                    isPossible = false;
                    break;
                }
                else
                {
                    l = i;
                    same = true;
                }
            }
        }
        else if (same)
        {
            if (a[i] != b[i])
            {
                check0 = no_of_zero[i] - no_of_zero[l];
                check1 = no_of_zero[i] - no_of_one[l];

                if (check0 != check1)
                {
                    isPossible = false;
                    printf("Got 0: %d, Got 1 : %d, left index :%d, right : %d\n", check0, check1, l, i);
                    break;
                }
                else
                {
                    l = i;
                    same = false;
                }
            }
        }
    }

    if (isPossible)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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