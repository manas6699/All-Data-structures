#include <iostream>
using namespace std;
#define MOD 1000000007;

//Recursive solution
long balancedBinaryTreeCount(int h);

//Memoization
long balancedBinaryTreeCountHelper(long arr[], int h);
int balancedBinaryTreeCountMemo(int h);

//Dynammic programming
int balancedBinaryTreeCountDp(int h);

int main()
{
    int h;
    cout << "Enter height ";
    cin >> h;

    cout << "Number of possible balanced bt found through recursion is " << balancedBinaryTreeCount(h) << endl;
    cout << "Number of possible balanced bt found through memoization is " << balancedBinaryTreeCountMemo(h) << endl;
    cout << "Number of possible balanced bt found through Dp is " << balancedBinaryTreeCountDp(h) << endl;

    return 0;
}

//Recursive solution
long balancedBinaryTreeCount(int h)
{
    if (h <= 1)
    {
        return 1;
    }

    long x = balancedBinaryTreeCount(h - 1);
    long y = balancedBinaryTreeCount(h - 2);

    long  temp1 = (x * x) % MOD;
    long  temp2 = (2 * x * y) % MOD;

    long ans = (temp1 + temp2) % MOD;

    return ans;
}

//Memoization
long balancedBinaryTreeCountHelper(long arr[], int h)
{
    if (h <= 1)
    {
        return 1;
    }

    if (arr[h] != -1)
    {
        return arr[h];
    }

    long x = balancedBinaryTreeCountHelper(arr , h - 1);
    long y = balancedBinaryTreeCountHelper(arr , h - 2);

    long  temp1 = (x * x) % MOD;
    long  temp2 = (2 * x * y) % MOD;

    arr[h] = (temp1 + temp2) % MOD;

    return arr[h];
}

int balancedBinaryTreeCountMemo(int h)
{
    long arr[h + 1];

    for (int i = 0; i <= h; i++)
    {
        arr[h] = -1;
    }

    return (int)balancedBinaryTreeCountHelper(arr, h);
}

//Dp
int balancedBinaryTreeCountDp(int h)
{
    long arr[h + 1];

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= h; i++)
    {
        long temp1 = (arr[i - 1] * arr[i - 1]) % MOD;
        long temp2 = (2 * arr[i - 1] * arr[i - 2]) % MOD;

        arr[i] = (temp1 + temp2) % MOD;
    }

    return (int)arr[h];
}