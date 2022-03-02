#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        //2,4,8.14

        long long int n, k;
        cin >> n >> k;

        //For Even Number
        if (n % 2 == 0)
        {
            //8,12
            if (n / 2 % 2 == 0)
            {
                cout << n / 2 << " " << n / 4 << " " << n / 4 << endl;
            }
            //14,10
            else
            {
                cout << n / 2 - 1 << " "

                     << n / 2 - 1 << " 2" << endl;
            }
        }

        //For Odd Number
        //Suppose, 7,9
        else

        {
            cout << "1 " << n / 2 << " " << n / 2 << endl;
        }
    }
}