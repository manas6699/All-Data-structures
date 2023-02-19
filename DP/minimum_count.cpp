#include <bits/stdc++.h>
using namespace std;

int dp(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
   
    for (int i = 2; i <= n; i++)
    {
         int minimum = INT_MAX;
        for (int j = 2; j < sqrt(n); j++)
        {
            int count = i - (j * j);
            minimum = min(count , minimum) + 1;
        }
        arr[i] = minimum ;
    }
    
    return arr[n];
}

int memoization(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 0;
    }
    int *arr = new int[n + 1];
    for (int i = 0; i <= n  ; i++)
    {
        arr[i] = -1;
    }
    
    
    arr[0] = 0;
    arr[1] = 1;

    if (arr[n] != -1)
    {
        return arr[n];
    }

    int minimum = INT_MAX;
    for (int i = 1; i <= sqrt(n) ; i++)
    {
        int count = memoization(n - (i*i));
        minimum = min(minimum , count);
    }
        return minimum + 1;

}

int min_count(int n)
{

    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int minimum = INT_MAX;
    for (int i = 1; i <= sqrt(n); i++)
    {
        int count = min_count(n - (i * i));
        minimum = min(minimum, count);
    }

    return minimum + 1;
}

int main()
{
    int n;
    cin >> n;
    int i = 0;
    cout << "Recursive approach : " << min_count(n) << endl;
    cout << "Memoization approach : " << memoization(n) << endl;
    cout << "Dp approach : " << dp(n) << endl;
    return 0;
}