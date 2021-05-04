c++
#include <bits/stdc++.h>
using namespace std;
#define MAX 1e8
//It will store Prime Numbers, True == Prime, False == Not Prime.
vector<bool> isPrime(MAX, true);

//This Vector will contain only prime Numbers
vector<int> primeNumber;

void Sieve_of_Eratosthenes()
{
    //Declaring All Numbers to Prime
    // memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++)
    {
        // printf("Checking Multiple of %d\n", i);
        //CrossingEach Multiple of i
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                // printf("Crossing %d\n", j);
                isPrime[j] = false;
            }
        }
    }

    //Adding to PrimeNumber Vector
    for (int i = 2; i < MAX; i++)
    {
        if (isPrime[i])
            primeNumber.push_back(i);
    }
}

int main()
{
    Sieve_of_Eratosthenes();
    for (int i = 1; i < primeNumber.size(); i += 100)
    {
        cout << primeNumber[i - 1] << endl;
    }
    cout << endl;
}