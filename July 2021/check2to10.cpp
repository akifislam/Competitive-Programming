#include <bits/stdc++.h>
using namespace std;

void check()
{
    for (int i = 1; i <= 10000000; i++)
    {
        bool possible = true;

        for (int j = 2; j <= 10; j++)
        {
            if (i % j != 0)
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    long long int N;
    cin >> N;
    cout << N / 2520 << endl;
}