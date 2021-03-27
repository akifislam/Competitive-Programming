#include <bits/stdc++.h>

using namespace std;

int main()
{

    string str;
    cin >> str;

    int length = str.length();
    int default_count = 0;
    int dcount = 0;

    bool isFirst = false;
    int left_end_length = 0;

    //Maximum of Default String
    for (int i = 1; i < length; i++)
    {
        if (str[i] != str[i - 1])
        {
            dcount++;
        }
        else
        {
            default_count = max(default_count, dcount);
            dcount = 0;
        }
    }

    default_count = max(default_count, dcount) + 1;
    //    cout << "Age thekei Ache : " << default_count + 1 << endl;

    //Check Two Sides/fff
    //    cout << "Left End :" << left_end_length << endl;

    //Right End
    dcount = 0;
    if (str[0] == str[length - 1])
    {
        cout << default_count << endl;
    }

    else
    {
        //Left Count
        int leftCount = 0, rightCount = 0;

        for (int i = 0; i < length; i++)
        {
            if (str[i] != str[i + 1])
                leftCount++;
            else
                break;
        }

        //Right Count
        for (int i = length - 1; i > 0; i--)
        {
            if (str[i] != str[i - 1])
            {
                rightCount++;
            }
            else
                break;
        }
        leftCount++;
        rightCount++;

        //    cout << "Both End Mirror : " << left_end_length + right_end_length << endl;
        cout << max(min(leftCount+rightCount,length), default_count) << endl;
    }
}