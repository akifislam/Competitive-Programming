//Trying to Optimize

#include <bits/stdc++.h>
using namespace std;
// void printarray(int size, bool arr[])
// {
//     cout << endl;
//     for (int i = 1; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void printarray(int size, int arr[])
// {
//     cout << endl;
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void printVector(int size, vector<int> vec)
// {
//     // cout << endl;
//     for (int i = 0; i < vec.size(); i++)
//     {
//         cout << vec[i] << " ";
//     }
//     cout << endl;
// }

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
                prev = input;
            }
        }
        // printarray(n, arr);
        // printarray(n + 1, visited_mini);

        vector<int> answer_mini;
        vector<int> answer_maxi;

        //Processing Minimum Permutation
        answer_maxi.push_back(arr[0]);
        answer_mini.push_back(arr[0]);

        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
            {

                //For Minimum Permutation
                for (int j = 1; j < arr[i]; j++)
                {
                    if (!visited_mini[j])
                    {
                        answer_mini.push_back(j);
                        visited_mini[j] = true;
                        break;
                    }
                }

                //For Maximum Permutation
                for (int j = arr[i] - 1; j > 0; j--)
                {
                    if (!visited_maxi[j])
                    {
                        answer_maxi.push_back(j);
                        visited_maxi[j] = true;
                        break;
                    }
                }
            }
            else
            {
                answer_mini.push_back(arr[i]);
                answer_maxi.push_back(arr[i]);
            }
        }
        
        //Printing Mini Vector
        for(auto it = answer_mini.begin(); it!=answer_mini.end(); it++) {
            cout<<*it<<" ";
        }
        cout<<endl;

        //Printing Maxi Vector
        for(auto it = answer_maxi.begin(); it!=answer_maxi.end(); it++) {
            cout<<*it<<" ";
        }
        cout<<endl;


    }
    return 0;
}