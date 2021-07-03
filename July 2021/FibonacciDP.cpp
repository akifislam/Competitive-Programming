#include <bits/stdc++.h>
using namespace std;
// The sequence is : 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987...
// It will return N-th Fibonacci Number
long long int DP[1000];

long long int Fibonacci(long long int N)
{

    if (N <= 2)
        return 1;
    else if (DP[N] != 0)
        return DP[N];

    DP[N] = Fibonacci(N - 1) + Fibonacci(N - 2);
    return DP[N];
}

int main()
{
    long long int input;
    cin >> input;
    cout << Fibonacci(input) << endl; //Without Memoization, Fib(50) takes huge time to run.
}