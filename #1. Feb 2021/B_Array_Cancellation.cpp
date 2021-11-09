//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-02-26 22:05:42
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long long int arr[n];

        long long int answer =0 ;

        long long int sum = 0;
       
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            
            sum+=arr[i];
            
            answer = max(0LL,sum);

        }

        cout<<answer<<endl;
    }
}