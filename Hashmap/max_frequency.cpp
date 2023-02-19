#include <bits/stdc++.h>
using namespace std;

void max_frequency(int* arr , int n)
{
    int count = 0;
    vector<int> output;
    unordered_map<int , bool> seen;
    for (int i = 0; i < n; i++)
    {
        if (seen.count(arr[i]) > 0)
        {
            continue;
            count++;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
        
        
    }
    
    cout << arr[count] << " ";

    
}

//              15

//      2 12 2 11 12 2 1 2 2 11 12 2 6 18 18
int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    max_frequency(arr, n);
    return 0;
}