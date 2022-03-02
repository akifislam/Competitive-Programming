#include <bits/stdc++.h>
using namespace std;

void check()
{
    for (int i = 1; i <= 100000; i++)
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
            cout << i <<", ";
        }
    }
}

int main()
{
    long long int N;
    check();
}