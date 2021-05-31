//HovalHaq!
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k, r = 1;
//         cin >> n >> k;
//         vector<int> C(26);
//         for (int i = 0; i < n; i++)
//         {
//             char c;
//             cin >> c;
//             C[c - 'a']++;
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             int l = __gcd(i, k), x = i / l, a = 0;
//             for (int c : C)
//                 a += c / x;
//             if (a >= l)
//                 r = max(r, i);
//         }
//         cout << r << "\n";
//     }

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    //is possible make beafutiful neckles size of multple k
    int n, k;
    cin >> n >> k;
    vector<int> fr(26, 0);

    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        fr[c - '0' - 49]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 26; j++)
        {
            cnt += (fr[j] / i);
        }
        cout << "Count Here : " << cnt << endl;
        while (cnt > 0 and k % cnt != 0)
            cnt--;
        cout << "Answer Pushed Here : " << cnt << endl;
        ans = max(cnt * i, ans);
    }
    cout << ans;
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
