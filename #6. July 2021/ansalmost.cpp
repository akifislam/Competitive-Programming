#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <map>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    int n, ms_size = 0, pos = 0, check = 1, i = 0;
    list<int> ms;
    list<int>::iterator it, t1, t2, temp;
    it = ms.begin();

    while (scanf("%d", &n) != EOF)
    {
        if (n == -1)
        {
            printf("%d\n", (*it));
            temp = it;
            it++;
            t1 = it; //3
            it--;
            if (it != ms.begin())
                it--; 
            t2 = it; //1
            
            ms.erase(temp);
            if (ms_size & 1)
                it = t2;
            else
                it = t1;
            ms_size--;
        }
        else if (n == 0)
        {
            ms_size = 0;
            ms.clear();
            it = ms.begin();
            printf("\n");
        }
        else
        {
            ms.push_back(n);
            ms_size++;
            //cout<<count<<endl;
            if (ms_size & 1)
                it++;
        }
    }
    return 0;
}