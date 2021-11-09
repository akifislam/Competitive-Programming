#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> vec(m);

        ll input;

        for (int i = 0; i < n; i++)
        {

            cin >> input;
            vec[input % m]++;
        }

        //Input Shesh

        int grouped_element = 0;
        int group_no = 0;

        // Divisible by m
        if (vec[0] > 0)
        {
            group_no++;
            grouped_element += max(1, vec[0]);
            vec[0] = 0;
        }

        //        cout<<"After Div M : "<< grouped_element <<endl;

        if (m % 2 == 0 && vec[m / 2])
        {
            //Divisible by m/2
            grouped_element += max(1, vec[m / 2]);
            if (vec[m / 2] > 0)
                group_no++;
            vec[m / 2] = (vec[m / 2] % 2);
            //            cout << "After Div M/2 : " << grouped_element << endl;
        }

        //Vector Print
        //        cout<<endl;
        //        cout<<"----"<<endl;
        //        for (int i = 0; i < vec.size(); i++) {
        //            cout<<vec[i]<<" ";
        //        }
        //        cout<<endl;
        //        cout<<"----"<<endl;

        //Check
        int right = m - 1;
        int left = 1;

        while (left < right)
        {
            //            cout<<"Group Count : "<<group_no<<endl;
            if (vec[left] > 0 && vec[right] > 0)
                group_no++;
            else
            {
                //                if (vec[left] > 0) group_no++;
                //                else if (vec[right] > 0) group_no++;

                left++, right--;
                continue;
            }

            int items_in_left = vec[left];
            int items_in_right = vec[right];

            if (items_in_left == items_in_right)
                grouped_element += items_in_left * 2;
            else
                grouped_element += min(items_in_left, items_in_right) * 2 + 1;

            left++;
            right--;
        }

        //        cout<<"Ans : "<<group_no + (n-grouped_element)<<endl;
        cout << group_no + (n - grouped_element) << endl;
    }
}