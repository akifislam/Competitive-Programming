#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, p[100005], d[100005], ans, max1, max2;
    max1 = max2 = 0;
    ans = 1;
    memset(d, 0, sizeof d);
    cin >> n;
    
    for (i = 1; i <= n; i++)
    {
        cin >> p[i];

        if (p[i] > max1)
        {
            max2 = max1;
            max1 = p[i];
            d[max1]--;
        }
        else if (p[i] > max2)
        {
            max2 = p[i];
            d[max1]++;
        }
    }
    for (i = 1; i <= n; i++)
        if (d[i] > d[ans])
            ans = i;
    cout << ans;
}