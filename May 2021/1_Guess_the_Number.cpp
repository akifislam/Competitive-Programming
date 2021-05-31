// __ SHERLOCK __

// This is a code for Interacitve Test Problem
// This code got accepted without using flush or scanf, printf
// But it is always better to use scanf, print for faster interaction

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int l = 1, r = 1000000;
    
    while (l != r)
    {

        int mid = (l + r + 1) / 2;
        cout << mid << endl;

        string response;
        cin >> response;


        if (response == "<")
            r = mid - 1;
        else
            l = mid;
    }


    cout << "! "<<l << endl;

}