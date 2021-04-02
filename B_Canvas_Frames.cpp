#include <bits/stdc++.h>
using namespace std;
 
int arr[101];
 
int main()
{
    int n, input;
    cin >> n;
 
    memset(arr, 0, sizeof(arr));
 
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr[input]++;
    }
 
    sort(arr, arr + 101, greater<int>());
 
    //Two Pointer Faltu
    int answer = 0;
    for (int i = 0; i < 101 && arr[i]!=0; i++)
    {
        answer+=(arr[i]/2);
    }
    
    

    cout<<answer/2<<endl;
}