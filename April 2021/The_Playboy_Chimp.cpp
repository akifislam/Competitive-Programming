//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-04-28 08:54:16

#include <bits/stdc++.h>


#define ll long long
#define lll __int128_t
#define pb push_back
#define All(x) (x).begin(), (x).end()
#define sz(z) (int)((z).size())

using namespace std;


void solve()
{
    ll int N;
    cin >> N;
    vector<ll> vec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    ll no_of_queries;
    cin >> no_of_queries;

    while (no_of_queries--)
    {
        ll input;
        cin >> input;

        //Finding Lower One
        auto shorter = lower_bound(All(vec),input)-vec.begin();
        if(shorter == 0){
            cout<<"X"<<" ";
        }
        else cout<<vec[shorter-1]<<" ";

        //Finding Taller
        auto taller = upper_bound(All(vec), input);
        if (taller != vec.end())
        {
            cout << *taller << endl;
        }
        else
            cout << "X" << endl;
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