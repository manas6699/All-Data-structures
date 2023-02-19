#include <bits/stdc++.h>
using namespace std;

bool checkMaxHeap(int arr[], int n)
{
    bool b = false;
    for (int i = 0; i < n - 4; i++)     // n - 4 korlam keno ki... otoobdhi traverse korbe
    {
        int lci = 2 * i + 1;
        int rci = 2 * i + 2;
        
        if ((arr[i] > arr[lci]) && (arr[i] > arr[rci]))
        {
            b = true;
        }
        else
        {
            b = false;
            break;
        }
    }
    return b;
}

int main()
{
    int arr[] = {10, 6, 7, 5, 14, 3, 2 , 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    if (arr[2] < arr[6])
    {
        cout << "checkpoint!" << endl;
    }
    if (checkMaxHeap(arr, n))
    {
        cout << "It's a max heap";
    }
    else
    {
        cout << "Sorry!";
    }

    return 0;
}