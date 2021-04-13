//Trying to Optimize

#include <bits/stdc++.h>
using namespace std;
void printarray(int size, bool arr[])
{
    cout << endl;
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printarray(int size, int arr[])
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printVector(int size, vector<int> vec)
{
    // cout << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, input;
        cin >> n;

        bool visited_mini[n + 1];
        bool visited_maxi[n + 1];
        memset(visited_mini, false, sizeof(visited_mini));
        memset(visited_maxi, false, sizeof(visited_maxi));

        vector<int> minimum_per(n);
        vector<int> maximum_per;
        int arr[n];
        // int arr_max[n];
        int prev = -1;

        for (int i = 0; i < n; i++)
        {
            cin >> input;
            arr[i] = input;
            // arr_max[i] = input;

            if (input != prev)
            {
                visited_mini[input] = true;
                visited_maxi[input] = true;
                minimum_per[i] = input;
                // maximum_per[i] = input;
                prev = input;
            }
        }
        // printVector(n,minimum_per);

        //Printing Minimum Permutation
        int k = 1;
        for (int i = 0; i < n && k <= n; i++)
        {
            if (minimum_per[i] == 0)
            {
                while (visited_mini[k] && k <= n)
                    k++;
                cout << k << " ";
                k++;
            }
            else
            {
                cout << minimum_per[i] << " ";
            }
        }
        cout << endl;

        // //Printing Maximum Permutation
        // k = n;
        // for (int i = 0; i < n && k <= n; i++)
        // {
        //     if (maximum_per[i] == 0)
        //     {
        //         while (visited_maxi[k] && k >= 0)
        //             k--;
        //         cout << k << " ";
        //         k--;
        //     }
        //     else
        //     {
        //         cout << maximum_per[i] << " ";
        //     }
        // }
        // cout << endl;

        /// Prepvious

        cout<<arr[0]<<" ";
        int endpoint;
        
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                //For Maximum Permutation
                for (int j = arr[i] - 1; j > 0; j--)
                {
                    if (!visited_maxi[j])
                    {
                        // maximum_per.push_back(j);
                        cout<<j<<" ";
                        visited_maxi[j] = true;
                        break;
                    }
                }
            }
            else
            {
                // maximum_per.push_back(arr[i]);
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;

        // //Printing Maxi Vector
        // for (auto it = maximum_per.begin(); it != maximum_per.end(); it++)
        // {
        //     cout << *it << " ";
        // }
        // cout << endl;
    }
}