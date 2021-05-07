#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int f;
        cin >> f;

        string S;

        cin >> S;

        bool Possible = true;

        for (int i = 0; i < f; i++)
        {
            for (int j = f - 1; i < j; j--)
            {
                if (S[j] == S[i] && S[j - 1] != S[i])
                {

                    Possible = false;

                    break;
                }
            }

            if (!Possible)
                break;
        }

        if (!Possible)

            cout << "NO" << endl;
        else

            cout << "YES" << endl;
    }
    //Done
}