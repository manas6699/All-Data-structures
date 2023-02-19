#include <bits/stdc++.h>
using namespace std;

int recursive_approach(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    // recursive calling
    int x = recursive_approach(n - 1);
    

    int y = recursive_approach(n - 2);

    int z = recursive_approach(n - 3);

    return x + y + z;
}

int memoization(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    int *arr = new int[n + 1];
    for (int i = 0; i <= n  ; i++)
    {
        arr[i] = -1;
    }
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
   return  memoization(n - 1) + memoization(n - 2) + memoization(n - 3);
}

int dp(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 4;
    }
    int *arr = new int[n + 1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    int result = 0;
    for (int i = 4; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        
    }
    
    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << "Recursive approach : " << recursive_approach(n) << endl;
    cout << "Memoization approach : " << memoization(n) << endl;
    cout << "Dp approach : " << dp(n) << endl;

    return 0;
}