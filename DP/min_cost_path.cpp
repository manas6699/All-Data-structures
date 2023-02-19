
#include <iostream>
using namespace std;

int dp(int **arr, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    // fill the last index
    output[m - 1][n - 1] = arr[m - 1][n - 1];

    // fill the last row (right to left)
    for (int j = n - 2; j >= 0; j--)
    {
        output[m - 1][j] = output[m - 1][j + 1] + arr[m - 1][j];
    }

    // fill the last column (bottom to top)
    for (int i = n - 2; i >= 0; i--)
    {
        output[i][n - 1] = output[i + 1][n - 1] + arr[i][n - 1];
    }
    // fill remaining cells
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j])) + arr[i][j];
        }
    }

    return output[0][0];
}
int memo_helper(int **arr, int m, int n, int i, int j, int **output)
{
    // base case
    if (i == m - 1 && j == n - 1)
    {
        return arr[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    // check if the answer is already available or not
    if (output[i][j] != -1)
    {
        return output[i][j];
    }

    // recursion calling
    int x = memo_helper(arr, m, n, i, j + 1, output);
    int y = memo_helper(arr, m, n, i + 1, j, output);
    int z = memo_helper(arr, m, n, i + 1, j + 1, output);

    // small calculation
    int a = min(x, min(y, z)) + arr[i][j];

    // save the answer
    output[i][j] = a;

    return a;
}

int memo(int **arr, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    return memo_helper(arr, m, n, 0, 0, output);
}
int rec_helper(int **arr, int m, int n, int i, int j)
{
    // base case
    if (i == m - 1 && j == n - 1)
    {
        return arr[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    // recursion calling
    int x = rec_helper(arr, m, n, i, j + 1);
    int y = rec_helper(arr, m, n, i + 1, j);
    int z = rec_helper(arr, m, n, i + 1, j + 1);

    // small calculation
    int ans = min(x, min(y, z)) + arr[i][j];
    return ans;
}
int rec(int **arr, int m, int n)
{
    return rec_helper(arr, m, n, 0, 0);
}
int main()
{
    int m, n;
    cin >> m >> n;
    int **x = new int *[m];
    for (int i = 0; i < m; i++)
    {
        x[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> x[i][j];
        }
    }

    cout << "Min Cost Path using recursion : " << rec(x, m, n) << endl;
    cout << "Min Cost Path using memoization : " << memo(x, m, n) << endl;
    cout << "Min Cost Path using dp : " << dp(x, m, n) << endl;

    return 0;
}
