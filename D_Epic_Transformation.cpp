// Getting Idea of 3 Kinds of Solution
// 1) Dynamic Programming
// 2) Sorting and Conquer
// 3) Using DS (Map), Priority Queue

//Tring Sorting

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        ll arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);

        //Two Pointer

        int answer = n;

        int i = 0;
        int j = (n + 1) / 2;

        //1 1 1 | 1 1 2
        while (i < (n / 2))
        {
            if (arr[i] != arr[j])
            {
                answer -= 2;
                
            }
            i++,j++;
        }
        cout << answer << endl;
    }
}