#include <bits/stdc++.h>
using namespace std;

int memo_helper(int arr[], int n);
int memoization(int n);

int rec(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 3;
    }
    int mod = (int)(pow(10, 9)) + 7;
    int m1 = rec(n - 1);
    int m2 = rec(n - 2);

    int temp1 = (int)(((long)(m1)*m1) % mod);
    int temp2 = (int)((2 * (long)(m1)*m2) % mod);
    int ans = temp1 + temp2;

    return ans;
}
int memoization(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }
    return memo_helper(arr, n);
}
int memo_helper(int arr[], int n)
{
    // base case
    if (n <= 1)
    {
        return 1;
    }
    // if (n == 2)
    // {
    //     return 3;
    // }

    // checking
    if (arr[n] != -1)
    {
        return arr[n];
    }

    int mod = (int)(pow(10, 9)) + 7;
    int m1 = memo_helper(arr, n - 1);
    int m2 = memo_helper(arr, n - 2);

    int temp1 = (int)(((long)(m1)*m1) % mod);
    int temp2 = (int)((2 * (long)(m1)*m2) % mod);
    int ans = (temp1 + temp2) % mod;

    arr[n] = ans;

    return arr[n];
}

int main()
{
    int hight;
    cin >> hight;

    cout << "Recursive approach : " << rec(hight) << endl;
    cout << "Memoization approach : " << memoization(hight) << endl;

    return 0;
}
