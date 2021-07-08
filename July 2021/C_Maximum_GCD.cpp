#include <bits/stdc++.h>
using namespace std;

int callgcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return callgcd(b, a % b);
}

int main()
{
    int t, arr[1050];
    scanf("%d", &t);

    getchar();
    string s;

    while (t--)
    {
        getline(cin, s);
        stringstream ss(s); //stringstream used.

        int j = 0;

        while (ss >> arr[j])
            j++;

        int answer = 1;

        for (int i = 0; i < j; i++)
        {
            for (int k = 0; k < j; k++)
            {
                if (i != k)
                    answer = max(answer, __gcd(arr[i], arr[k]));
            }
        }
        printf("%d\n", answer);
        // printf("End\n");
    }
    return 0;
}