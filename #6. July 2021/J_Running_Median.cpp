//Akif Islam (__SHERLOCK__)
//Date: 2021-07-28 21:58:33

#include <bits/stdc++.h>

using namespace std;
// #define ll int
#define ll long long int

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    ll input;

    multiset<ll> ms;
    auto it = ms.begin();

    ll median = *it; //Initialize
    ll ms_size = 0;

    while (scanf("%lld", &input) != EOF)
    {
        // Number Input
        if (input == 0)
        {
            //Clear All
            ms.clear();
            ms_size = 0;
            it = ms.begin();
            printf("\n");

            // it = ms.begin();
            // median = *it;
        }

        else if (input != -1)
        {
            ms.insert(input);
            ms_size++;

            //If it is the 1st item

            if (ms_size % 2 == 1)
            {
                it++;
            }

            // cout << "Median : " << median << endl;
        }

        // 1 2 3 4
        //Query
        else if (input == -1)
        {
            printf("%d\n", (*it));

            auto deleting_pointer = it;

            it++;

            auto p1 = it; //Next Item

            it--;

            if (it != ms.begin())
                it--;
            auto p2 = it; //Previous Item

            if (ms_size % 2 == 0)
            {
                it = p1;
            }
            else
            {
                it = p2;
            }
            ms.erase(deleting_pointer);
            ms_size--;
        }
    }
}