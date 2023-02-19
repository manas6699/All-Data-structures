#include <bits/stdc++.h>
using namespace std;

int loot_house_helper(int i, int n, int arr[])
{
    //  base case
    if (i >= n)
    {
        return 0;
    }

    int a = arr[i] + loot_house_helper(i + 2, n, arr);
    int b = loot_house_helper(i + 1, n, arr);

    return max(a, b);
}
int loot_house(int arr[], int n)
{
    // recurrence relation
    // rec(i , n) = max(arr[i] + rec(i + 2 , n) , rec(i + 1 , n));

    int i = 0;
    return loot_house_helper(i, n, arr);
}

int dp(int n, int arr[])
{
    int *dp = new int[n];
    dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0]);

    for (int i = 2; i <= n - 1; i++)
    {
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
}
int memo_helper(int i , int n , int arr[])
{
    if (i >= n)
    {
        return 0;
    }
    
    int a = arr[i] + memo_helper(i + 2, n, arr);
    int b = memo_helper(i + 1, n, arr);

    return max(a , b);
}
int memoization(int n, int arr[])
{
    int *memo = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        memo[i] = -1;
    }
    int i = 0;
    return memo_helper(i , n , arr);
}

int main()
{
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Recursive approach : " << loot_house(arr, n) << endl;
    cout << "Memoization approach : " << memoization(n , arr)  << endl;
    cout << "DP approach : " << dp(n, arr) << endl;
    return 0;
    //              10 2 30 20 3 50
}