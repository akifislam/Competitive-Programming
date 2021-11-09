#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string a, b;
        cin >> a >> b;
   
        int total_letters = a.length() + b.length();

        //Finding Matched Part
        int count = 0;
        int matched_letters = 0;

        for (int i = 0; i < a.length(); i++)
        {
            for (int j = 0; j < b.length(); j++)
            {
                if (a[i] == b[j])
                {
                    int temp_i = i;
                    int temp_j = j;
                    count = 0;
                    while (temp_i < a.length() && temp_j < b.length())
                    {
                        if (a[temp_i] == b[temp_j])
                        {
                            count++;
                            matched_letters = max(count,matched_letters);
                            // cout << "Count : " << count << endl;
                            // matched_letters = max(count, matched_letters);
                            temp_i++, temp_j++;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        cout<<total_letters - 2*matched_letters <<endl;
    }
}