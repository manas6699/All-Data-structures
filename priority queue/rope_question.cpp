#include <bits/stdc++.h>
using namespace std;

int udgandu(int arr[], int n)
{

    vector<long> manas;
    priority_queue<long, vector<long>, greater<long>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long a = 0;
    long b = 0;
    long x = 0;

    while (pq.size() != 1)
    {
        a = pq.top();

        pq.pop();
        b = a + pq.top();
        pq.pop();
        pq.push(b);

        manas.push_back(b);
    }

    for (int i = 0; i < manas.size(); i++)
    {

        x += manas[i];
    }
    return x;
}


int main()
{
    int arr[] = {4, 2, 7, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << udgandu(arr, n);

    return 0;
}