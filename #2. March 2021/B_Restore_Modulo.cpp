#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        int n;
        cin >> n;
        ll arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        //Finding C in Mixed Array (Pos Dif, Neg Dif)
        ll c = -1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                c = arr[i] - arr[i - 1];
                break;
            }
        }
        //    cout<<"C = "<<c<<endl;
        if (c != -1)
        {
            //Here means there is a valid answer of m and c
            //Searching M
            ll m = -1;
            for (int i = 1; i < n; i++)
            {
                if (arr[i] < arr[i - 1])
                {
                    m = (arr[i - 1] + c) - arr[i];
                    break;
                }
            }

            // cout << "m = " << m << endl;

            if (m != -1)
            {
                //Check Full PATH
                bool isOkay = true;
                for (int i = 1; i < n; i++)
                {
                    if ((arr[i - 1] + c) % m != arr[i])
                    {
                        isOkay = false;
                        break;
                    }
                }
        
                if (isOkay && arr[0] < m)
                    cout << m << " " << c << endl;
                else
                    cout << -1 << endl;
            }

            else {
                bool isOkay = true;
                for (int i = 1; i < n; i++)
                {
                    if(arr[i]-arr[i-1] != c){
                        isOkay = false;
                        break;
                    }
                }
                if(isOkay) cout<<0<<endl;
                else cout<<-1<<endl;
                
            }
        }
        else
        {
            // Case 1 : All Increasing Array
            // Case 2 : All Decreasing Array
            // Case 3 : All Equal Array
            //Answer would be 0 or -1
            int check_dif = arr[1] - arr[0];
            int i = 0;

            for (i = 1; i < n; i++)
            {
                if (arr[i] - arr[i - 1] != check_dif)
                    break;
            }
            //    cout<<"Difference : "<<check_dif<<endl;
            if (i == n)
                cout << 0 << endl;
            else
                cout << -1 << endl;
        }
    }
}
