#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> SQ_NUM;
vector<ll> divisor(ll x)
{
    vector<ll> vec;
    vec.push_back(1);
    vec.push_back(x);

    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            vec.push_back(i);
            if (x / i != i)
            {
                vec.push_back(x / i);
            }
        }
    }
    sort(vec.begin(), vec.end());
    return vec;
}

void generateSquareNumber(ll N)
{
    for (ll i = 2; i * i <= N; i++)
    {
        SQ_NUM.push_back(i * i);
    }
}

int main()
{
    ll N;
    cin >> N;
    generateSquareNumber(N);
    vector<ll> divisors = divisor(N);

    // i = Max. Divisor
    ll i = divisors.size() - 1;

    bool isBeautiful = true;
    while (i >= 0)
    {
        bool isBeautiful = true;

        for (ll j = 0; j < SQ_NUM.size(); j++)
        {
            if (divisors[i] % SQ_NUM[j] == 0)
            {
                isBeautiful = false;
                break;
            }
        }
        
        if (isBeautiful)
            break;

        i--;
    }
    cout << divisors[i] << endl;
}