#include <bits/stdc++.h>
using namespace std;


// Got Idea from Mhamuda's Solution

int main()
{
    // Sieve_of_Eratosthenes();

    int n;
    cin >> n;

    if (n > 2)
        cout << 2 << endl;
    else
        cout << 1 << endl;

    //Printing Answer
    vector<int> answer(n + 2);

    for (int i = 2; i < n + 2; i++)
    {
        if (!answer[i])
        {
            answer[i] = 1;
            for (int j = i + i; j < n + 2; j += i)
            {
                answer[j] = 2;
            }
        }
    }

    //Print
    for (int i = 2; i < n + 2; i++)
        cout << answer[i] << " ";
    cout << endl;
}