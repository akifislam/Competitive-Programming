#include <bits/stdc++.h>
using namespace std;

#define ll long long int
vector<ll> series;

void solve()
{
    long long int N;

    cin >> N;

    auto XX = lower_bound(series.begin(), series.end(), N);
    ll Block = XX - series.begin();

    ll pointerx;
    pointerx = Block;

    if (!binary_search(series.begin(), series.end(), N))
        pointerx--;

    else
    {
        ll xx, yy;
        xx = Block;

        cout << xx << " 1" << endl;
        return;
    }

    ll sp = series[pointerx] + 1;
    ll row = 1;
    ll column = Block;

    for (int i = 0; i < Block - 1; i++)
    {

        if (sp == N)
        {
            cout << row << " " << column << endl;
            return;
        }

        else
        {
            row++;
            sp++;
        }
    }

    for (int i = 0; i < Block - 1; i++)
    {
        if (sp == N)
        {
            cout << row << " " << column << endl;
            return;
        }

        column--;
        sp++;
    }

    // :(
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll summation = 0;
    series.push_back(0);

    for (int k = 1; summation <= 1000000008LL; k += 2)
    {
        summation += k;
        series.push_back(summation);
    }

    int TT = 1;
    cin >> TT;

    while (TT--)
    {
        solve();
    }
    return 0;
}