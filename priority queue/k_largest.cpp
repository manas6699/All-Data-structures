#include <bits/stdc++.h>
using namespace std;

void k_smallest(int arr[], int n, int k)
{
    priority_queue<int, vector<int> , greater<int>> pq;
    for (int i = 0; i < k ; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n ; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main()
{

    int arr[] = {5, 6, 9, 12, 3, 13, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    k_smallest(arr, n, k);

    return 0;
}