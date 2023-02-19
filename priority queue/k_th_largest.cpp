#include <bits/stdc++.h>
using namespace std;

void k_smallest(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < n ; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = 0; i < k - 1 ; i++)
    {
        pq.pop();
    }
    cout << k << " th largest element is : " << pq.top();
    
}

int main()
{

    int arr[] = {5, 6, 9, 12, 3, 13, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    k_smallest(arr, n, k);

    return 0;
}