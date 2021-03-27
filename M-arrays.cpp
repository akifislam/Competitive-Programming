#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        int rem[m];
        memset(rem, 0, sizeof(rem));

        ll input;

        for (int i = 0; i < n; i++)
        {

            cin >> input;
            rem[input % m]++;
        }

        //Input Shesh
        int group_no = 0;

        // Divisible by m
        if (rem[0] > 0)
            group_no++;
        rem[0] = -1;

        cout << endl;
        cout << "----" << endl;
        for (int i = 0; i < m; i++)
        {
            cout << rem[i] << " ";
        }
        cout << endl;
        cout << "----" << endl;

        //Check
        int right = m - 1;
        int left = 1;

        while (left <= right)
        {
            if (rem[left] != 0 || rem[right] != 0)
                group_no++;

            left++;
            right--;
        }

        //        cout<<"Ans : "<<group_no + (n-grouped_element)<<endl;
        cout << group_no << endl;
    }
}