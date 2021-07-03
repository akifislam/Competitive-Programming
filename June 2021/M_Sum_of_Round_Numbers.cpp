//Akif Islam (__SHERLOCK__)
//Date: 2021-06-29 04:05:13

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

int non_zero = 0;

vector<int> getDigits(int N)
{
    non_zero = 0;
    vector<int> digits;

    while (N > 0)
    {
        digits.push_back(N % 10);
        if (N % 10 != 0)
            non_zero++;
        N /= 10;
    }

    return digits;
}
void solve()
{
    ll N;
    cin >> N;

    vector<int> digits = getDigits(N);

    int weight = 1;
    cout << non_zero << endl;
    for (int i = 0; i < digits.size(); i++)
    {
        if (digits[i] != 0)
        {
            cout << digits[i] * weight << " ";
        }
        weight *= 10;
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}