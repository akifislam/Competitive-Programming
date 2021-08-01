//Akif Islam (__SHERLOCK__)
//Date: 2021-07-29 10:18:38
// Took help from the tutorials & solutions :(

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

void solve()
{
    ll N, input;
    ll max_val = 0;
    ll sum = 0;
    ll FREQ[100005];

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        // cout << "Sum : " << sum << endl;
        // cout << "MaxVal : " << max_val << endl;

        cin >> input;

        if (input > max_val)
        {
            FREQ[input] = 1;
            sum = max_val;
            max_val = input;
        }
        else if (input > sum)
        {
            FREQ[max_val]--;
            sum = input;
        }

        //Print
        // for (int i = 1; i <= 5; i++)
        // {
        //     cout << FREQ[i] << " ";
        // }
        // cout << endl;
    }

    //Process
    ll ans = 1;
    for (int i = 1; i <= N; i++)
    {
        if (FREQ[i] < FREQ[ans])
            ans = i;
    }
    cout << ans << endl;
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