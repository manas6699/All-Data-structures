#include <bits/stdc++.h>
using namespace std;

void kSortedrray(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    int j = 0;
    for (int i = k; i < n; i++)
    {
        arr[j] = pq.top();
        cout << pq.top() << " ";
        pq.pop();
        
        pq.push(arr[i]);
        cout << pq.top() << " ";
        
        j++;
    }
    while (!pq.empty())
    {
        arr[j] = pq.top();
        pq.pop();
        cout << pq.top() << " ";
    }
}
int main()
{
    int n = 5;
    int arr[n] = {10, 12, 6, 7, 9};
    int k = 3;

    kSortedrray(arr, n, k);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    return 0;
}