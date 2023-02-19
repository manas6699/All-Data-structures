#include <bits/stdc++.h>
using namespace std;

vector<int> remove_duplicates(int* a , int size)
{
    vector<int> output;
    unordered_map<int , bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
        
    }
    return output;
    
}

int main()
{

    cout << "Enter the size of the array : ";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> output = remove_duplicates(arr , n);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
    
    
    

    return 0;
}