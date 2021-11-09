#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        long long int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        if (k == 0)
            cout << "YES" << endl;
        else if (k * 2 + 1 > n)
            cout << "NO" << endl;
        else
        {
            int count = 0;
            bool isPossible = true;

            for (int i = 0, j=n-1; i<k; i++, j--)
            {
                count++;
                if (s[i] != s[j])
                {
                    isPossible = false;
                    break;
                }
            }
            // cout << "Count : " << count << endl;
            if (!isPossible)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
}