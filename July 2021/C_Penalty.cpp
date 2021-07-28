#include <bits/stdc++.h>

using namespace std;

//Penalty

void solve()
{
    string GOAL_PREDICTION;

    cin >> GOAL_PREDICTION;

    int GOAL_OF_A = 0;
    int GOAL_OF_B = 0;

    int REM_CHANCES_FOR_A = 5;
    int REM_CHANCES_FOR_B = 5;

    int G1 = 10;

    for (int i = 0; i < 10; i++)
    {

        if (i % 2 == 0)
        {
            if (GOAL_PREDICTION[i] == '1' || GOAL_PREDICTION[i] == '?')
            {

                GOAL_OF_A++;
            }

            REM_CHANCES_FOR_A--;
        }
        else
        {
            if (GOAL_PREDICTION[i] == '1')
            {
                GOAL_OF_B++;
            }

            REM_CHANCES_FOR_B--;
        }

        if (GOAL_OF_A > GOAL_OF_B && GOAL_OF_A - GOAL_OF_B > REM_CHANCES_FOR_B)
        {
            G1 = i + 1;

            break;
        }

        if (GOAL_OF_B > GOAL_OF_A && GOAL_OF_B - GOAL_OF_A > REM_CHANCES_FOR_A)
        {
            G1 = i + 1;

            break;
        }
    }

    GOAL_OF_A = 0, GOAL_OF_B = 0;
    REM_CHANCES_FOR_A = 5;
    REM_CHANCES_FOR_B = 5;

    int G2 = 10;

    for (int i = 0; i < 10; i++)
    {

        if (i % 2 == 0)
        {
            if (GOAL_PREDICTION[i] == '1')
            {
                GOAL_OF_A++;
            }

            REM_CHANCES_FOR_A--;
        }
        else
        {

            if (GOAL_PREDICTION[i] == '1' || GOAL_PREDICTION[i] == '?')
            {
                GOAL_OF_B++;

                //,,
            }
            REM_CHANCES_FOR_B--;
        }

        if (GOAL_OF_B > GOAL_OF_A && GOAL_OF_B - GOAL_OF_A > REM_CHANCES_FOR_A)
        {
            G2 = i + 1;

            break;
        }
        if (GOAL_OF_A > GOAL_OF_B && GOAL_OF_A - GOAL_OF_B > REM_CHANCES_FOR_B)
        {
            G2 = i + 1;

            break;
        }
    }

    //    cout << min(G1, G2) << endl;
    //    cout << min(G1, G2) << endl;
    cout << min(G1, G2) << endl;

    //FINISH
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}