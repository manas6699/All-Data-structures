#include <bits/stdc++.h>
using namespace std;
int findNum(int arr[], int n, int key)
{
    if (arr [n] == key)
    {
        return n;
    }
    
    if (n == 0)
    {
        return -1;
    }
    else{
        return findNum(arr , n - 1 ,key);
    }
    
    
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key{};
    cin >> key;

    cout << findNum(arr, n, key);

    return 0;
}
