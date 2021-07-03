#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll reverseInt(ll x)
{

    ll reversed_number = 0;

    while (x > 0)
    {
        reversed_number = (reversed_number * 10) + (x % 10);
        x /= 10;
    }
    // cout << "Returning : " << reversed_number << endl;
    return reversed_number;
}

int main()
{

    ll input;

    while (scanf("%ld",&input) == 1)
    {
        bool isPrime = true;

        for (ll i = 2; i * i <= input; i++)
        {
            if (input % i == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (!isPrime)
        {
            cout << input << " is not prime." << endl;
        }

        else
        {
            ll reversed_int = reverseInt(input);
            bool alsoprime = true;

            for (ll i = 2; i * i <= reversed_int; i++)
            {
                if (reversed_int % i == 0)
                {
                    alsoprime = false;
                    break;
                }
            }

            if (alsoprime && input != reversed_int)
                cout << input << " is emirp." << endl;
            else
                cout << input << " is prime." << endl;
        }
    }
}