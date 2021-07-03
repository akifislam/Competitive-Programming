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