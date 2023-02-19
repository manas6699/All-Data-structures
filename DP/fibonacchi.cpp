#include <bits/stdc++.h>
using namespace std;

int fib_1(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = fib_1(n - 1);
    int b = fib_1(n - 2);

    return a + b;
}
int fib_2_helper(int arr[], int n)
{
    // base case
    if (n <= 1)
    {
        return n;
    }

    // checking
    if (arr[n] != -1)
    {
        return arr[n];
    }

    // bakchodi
    int a = fib_2_helper(arr, n - 1);
    int b = fib_2_helper(arr, n - 2);
    arr[n] = a + b;
    return arr[n];
}
int fib_2(int n)
{
    int arr[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }
    return fib_2_helper(arr, n);
}
int fib_3(int n)
{
    int *arr = new int[n + 1];

    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << n << "th fibonacchi number is : " << fib_1(n) << endl;
    cout << n << "th fibonacchi number is : " << fib_2(n) << endl;
    cout << n << "th fibonacchi number is : " << fib_3(n) << endl;

    return 0;
}