// NSUPS contests are awesome :)
// I wish I could admit in NSU :(

//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-07-01 17:58:44
// TWO POINTER

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(ll N, ll S)
{

    vector<ll> vec(N);
    ll input;
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }
    if (sum < S)
    {
        cout << 0 << endl;
        return;
    }
    ll left, right, answer = N;

    left = 0;
    right = 0;
    sum = vec[right];

    while (right < N && left < N)
    {
        // cout << "Left : " << left << " "   << "Right " << right << endl;
        if (sum >= S)
        {
            // cout << "Sum is : " << sum << endl;
            // cout << "Ans Push : " << right - left + 1 << endl;
            answer = min(answer, right - left + 1);
            sum -= vec[left];
            left++;
        }
        else if (sum < S)
        {
            right++;
            sum += vec[right];
        }
    }

    cout << answer << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    ll N, S;
    while (cin >> N >> S)
    {
        solve(N, S);
    }
    return 0;
}