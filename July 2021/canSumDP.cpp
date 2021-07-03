#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// Is it possible to reach a targetSum from some numbers? Return YES or NO.

int DP[100000];
vector<ll> numbers;

bool canSum(ll targetSum)
{
    if (targetSum == 0)
        return true;
    if (targetSum < 0)
        return false;
    if (DP[targetSum] != -1)
        return DP[targetSum];

    for (int i = 0; i < numbers.size(); i++)
    {
        if (canSum(targetSum - numbers[i]))
        {
            DP[targetSum] = true;
            return true;
        }
    }
    DP[targetSum] = false;
    return false;
}

int main()
{
    memset(DP, -1, sizeof(DP));
    ll N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        ll input;
        cin >> input;
        numbers.push_back(input);
    }
    ll targetSum;
    cin >> targetSum;
    cout << canSum(targetSum) << endl;
}