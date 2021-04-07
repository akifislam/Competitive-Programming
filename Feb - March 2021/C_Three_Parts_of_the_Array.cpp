//__SHERLOCK__
//Commitment leads to action.
//Date: 2021-02-24 22:05:54
#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    int n;
    cin>>n;
 
    long long int arr[n];
 
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
 
    //Two Pointer Method
    long long int left = 0, right = n-1;
    long long int sumleft = 0;
    long long int sumright = 0;
 
    long long int sum = 0;
 
    while(left<=right) {

        if(sumleft==sumright) {
            sum = sumleft;
            if(left==right) break;
            else {
                sumleft+=arr[left];
                sumright+=arr[right];
            }
        }
 
        while (sumleft<sumright) {
            sumleft+=arr[left];
            left++;
           
        }

        while (sumleft>sumright) {
            sumright+=arr[right];
            right--;
          
        } 
 
    }
 
    cout<<sum<<endl;
 
 
 
 
}
 