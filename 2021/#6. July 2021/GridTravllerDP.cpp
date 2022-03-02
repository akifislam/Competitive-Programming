#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// how many ways we can travel from (1,1) to (m,n)?

ll DP[1000][1000];

ll GridTraveller(ll i, ll j)
{
    //If grid size is 0 (which is impossible), return 0;

    if (i == 0 || j == 0)
        return 0;
    //If Grid size 1 x m , or n x 1, then there is only one way.
    if (i == 1 || j == 1)
        return 1;
    if (DP[i][j] != 0)
        return DP[i][j];

    DP[i][j] = (GridTraveller(i - 1, j) + GridTraveller(i, j - 1));
    return DP[i][j];
}

int main()
{
    long long int n, m;
    cin >> n >> m;
    cout << GridTraveller(n, m) << endl; // GridTraveller(18,18) // 2333606220
}