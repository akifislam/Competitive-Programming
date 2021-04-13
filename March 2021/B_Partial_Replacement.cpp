#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size, k;
        cin >> size >> k;

        string str;
        cin >> str;

        //Input Done

        int start = -1, end = -1;

        //Check First Star
        for (int i = 0; i < size; i++)
        {
            if (str[i] == '*')
            {
                start = i;
                break;
            }
        }

        //Check Last Start
        for (int i = size - 1; i >= 0; i--)
        {
            if (str[i] == '*')
            {
                end = i;
                break;
            }
        }

        //Done
        int answer = 2;

        // printf("FStar : %d, LStar %d\n",start,end);
        if (start < end)
            answer = 2;

        else
        {
            answer = 1;
            cout << answer << endl;
            continue;
        }

        //Check
        int i = start;

        while (i < end)
        {   
            // printf("i = %d, Answer : %d\n",i,answer);
            if (str[i + k] != '*')
            {
                //Find Star
                for (int j = i+k; j>i; j--)
                {
                    if(str[j]=='*') {
                        answer++;
                        i=j;
                        break;
                    }
                }

            }

            else
            {
                answer++;
                i+=k;
            }
        }
        cout<<answer-1<<endl;
    }
}