//Akif Islam (__SHERLOCK__)
//Date: 2021-07-14 12:22:30

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
    int a = 22; //10110
    int b = 26; //11010
    printf("AND : %d\n", (a & b));
    printf("OR : %d\n", (a | b));
    printf("X-OR : %d\n", (a ^ b));
    printf("NOT: %d\n", (~a));

    cout << (3 << 2) << endl;


    int x = 5328;                          // 00000000000000000001010011010000
    cout << __builtin_clz(x) << "\n";      // 19
    cout << __builtin_ctz(x) << "\n";      // 4
    cout << __builtin_popcount(x) << "\n"; // 5
    cout << __builtin_parity(x) << "\n";   // 1
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