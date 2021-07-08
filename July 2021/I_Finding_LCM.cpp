//Akif Islam (__SHERLOCK__)
//Date: 2021-07-06 19:42:14

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
ll tc = 1;
vector<ll> get_divisors(ll num)
{

    vector<ll> D;
    D.pb(1);
    D.pb(num);

    for (ll i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            D.pb(i);
            if (i != num / i)
            {
                D.pb(num / i);
            }
        }
    }
    sort(All(D));
    return D;
}

ll solve(ll a, ll b, ll L)
{

    ll answer = 0;
    cout << "Case " << tc++ << ": ";
    //Corner Case
    ll LCM_val = lcm(a, b);
    // cout<<LCM_val<<endl;
    if (LCM_val > L)
    {
        cout << "impossible" << endl;
        return -1;
    }
    else if (LCM_val == L)
    {

        cout << 1 << endl;
        answer = 1;
        return answer;
    }
    else
    {
        if (L % a != 0 || L % b != 0)
        {
            cout << "impossible" << endl;
            return -1;
        }

        //Process
        vector<ll> div_a = get_divisors(a);
        vector<ll> div_b = get_divisors(b);
        vector<ll> div_L = get_divisors(L);
        ll limit = div_L.size();
        // cout<<div_a<<endl;
        // cout<<div_b<<endl;
        // cout<<div_L<<endl;

        //Finding Unique Divisor for L
        ll i = 0;

        for (i = 0; i < limit; i++)
        {
            if (binary_search(All(div_a), div_L[i]) != div_L[i] && binary_search(All(div_b), div_L[i]) != div_L[i])
            {
                if (a * b * div_L[i] >= L && lcm(lcm(a, b), div_L[i]) == L)
                {
                    cout << div_L[i] << endl;
                    return div_L[i];
                }
            }
        }

        //Check
    }
    return -1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        ll a, b, L;
        cin >> a >> b >> L;
        solve(a, b, L);

        //Checking
        // ll programmed_output = solve(a, b, L);
        // if (lcm(lcm(a, b), programmed_output) == L)
        // {
        //     cout << "OKAY" << endl;
        // }
        // else
        // {
        //     cout << "WA" << endl;
        // }
    }
    return 0;
}