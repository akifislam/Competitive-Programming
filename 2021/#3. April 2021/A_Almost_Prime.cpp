#include <bits/stdc++.h>
using namespace std;
#define MAX 3100
//It will store Prime Numbers, True == Prime, False == Not Prime.
bool isPrime[MAX];

//This Vector will contain only prime Numbers
vector<int> primeNumber;

void Sieve_of_Eratosthenes()
{
    //Declaring All Numbers to Prime
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i * i <= MAX; i++)
    {
        // printf("Checking Multiple of %d\n", i);
        //CrossingEach Multiple of i
        for (int j = i + i; j < MAX; j += i)
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
{   Sieve_of_Eratosthenes();
    int n;
    cin >> n;


    int almost_prime = 0;
    int prime_divisor = 0;

    for (int i = 6; i <=n; i++)
    {
        int cur = i;
        prime_divisor = 0;

        for (int j = 1; j<=cur ; j++)
        {
            if(cur % j == 0){
                if(binary_search(primeNumber.begin(), primeNumber.end(),j))
                    prime_divisor++;
            }
        }
        if(prime_divisor == 2) almost_prime++;
        
    }
    cout<<almost_prime<<endl;

    
}