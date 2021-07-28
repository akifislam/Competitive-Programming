#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, a, b;
        string s;

        cin >> n >> a >> b >> s;
        unique(s.begin(), s.end());
        cout << s << endl;
        // int m = unique(s.begin(), s.end()) - s.begin();
        // cout << m << endl;

        // cout << n * a + max(n * b, (m / 2 + 1) * b) << '\n';
    }
}