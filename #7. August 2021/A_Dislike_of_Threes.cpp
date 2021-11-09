#include <bits/stdc++.h>

using namespace std;

vector<int> num;

void solve()
{
    int N;
    
    


    cin >> N;

    cout << num[N - 1] << endl;

    // :( )

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);




    for (int k = 1; k <= 5100; k++)
    {

        if (k % 3 == 0 || k % 10 == 3)
            continue;
        else
            num.push_back(k);
    }

    int TT = 1;
    cin >> TT;



    while (TT--)
    {
        solve();
    }
    return 0;
}