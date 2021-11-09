#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, no_of_query;
        cin >> n >> no_of_query;

        string str;
        cin >> str;

        while (no_of_query--)
        {
            int left, right;
            cin >> left >> right;
            // left--,right--;
            string sub_string="";
            //Making Substring
            for (int i = left - 1; i < right; i++)
            {
                sub_string.push_back(str[i]);
            }

            // cout << "Sub String : " << sub_string << endl;

            //Check
            int count = 0;
            string derived_string="";
            int j = 0;

            for (int i = 0; i < n && j < sub_string.length(); i++)
            {
                if (count == 2){
                    count = 0;
                    continue;
                }
                if (sub_string[j] == str[i])
                {
                    count++;
                    j++;
                    derived_string.push_back(str[i]);
                    // cout<<"Derived : "<<derived_string<<endl;
                }
                else
                {
                    count = 0;
                }
            }
            puts(sub_string == derived_string ? "YES" : "NO");
        }
    }
}
