//Learning from Tutorial
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    s = "00" + s;
    //Why? Because if input is only 1 digit, then looping 3 loop will fail.

    //Calculating Length
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int a = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0') * 1;
                if (a % 8 == 0)
                {
                    cout << "YES" << endl;
                    cout << a << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
}