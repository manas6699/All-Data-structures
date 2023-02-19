#include <bits/stdc++.h>
using namespace std;

int minimum(int prices[], int n)
{
    int lsf = INT_MAX; // least so far
    int op = 0;        // overall profit
    int pist = 0;      // profit if sold today

    for (int i = 0; i < n; i++)
    {
        if (prices[i] < lsf)
        {                    
            lsf = prices[i]; 
        }
        pist = prices[i] - lsf; // calculating profit if sold today by, Buy - sell
        if (op < pist)
        {              // if pist is more then our previous overall profit
            op = pist; // update overall profit
        }
    }
    return op;
}

int main()
{
    int n = 6;
    int arr[n] = {7, 1, 5, 3, 6, 4};

    cout << minimum(arr, n);

    return 0;
}