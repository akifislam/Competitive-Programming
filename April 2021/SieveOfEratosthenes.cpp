#include <bits/stdc++.h>
using namespace std;
#define MAX 1100
//It will store Prime Numbers, True == Prime, False == Not Prime.
bool isPrime[MAX];

//This Vector will contain only prime Numbers
vector<int> primeNumber;

void Sieve_of_Eratosthenes()
{
    //Declaring All Numbers to Prime
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i*i <=MAX; i++)
    {
        // printf("Checking Multiple of %d\n", i);
        //CrossingEach Multiple of i
        for (int j = i+i; j < MAX; j += i)
        {
            // printf("Crossing %d\n", j);
            if (isPrime[j])
                isPrime[j] = false;
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
    for (int i = 0; i < primeNumber.size(); i++)
    {
        cout << primeNumber[i] << " ";
    }
    cout << endl;
}