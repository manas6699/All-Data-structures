#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 11;
    int arr[n] = { 88 , 99 , 52 , 33 , 96 , 558 , 20 , 2 , 3 , 54 , 1};
    sort(arr, arr + n);
    int k = 5;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}