#include <bits/stdc++.h>
using namespace std;

int dp(int n, int* wt, int* val, int W)
{
    int i, w;
    // n+1 ar mw+1 size er 2D vector nilam
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            // base case hit korle okhane 0 diye debo
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
            }

            else if (wt[i - 1] <= w)
            {

                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else
            {

                K[i][w] = K[i - 1][w];
            }
        }
        
    }
    return K[n][W];
}
int memo_helper(int n, int *weight, int *value, int mw, int **output, int i)
{
    // base case
    if (n == 0 || mw == 0)
    {
        return 0;
    }
    if (weight[0] > mw)
    {
        return memo_helper(n - 1, weight + 1, value + 1, mw, output, i);
    }
    // small check
    if (output[i][i] != -1)
    {
        return output[i][i];
    }

    int x = memo_helper(n - 1, weight + 1, value + 1, mw - weight[0], output, i + 1) + value[0];
    int y = memo_helper(n - 1, weight + 1, value + 1, mw, output, i + 1);

    int a = max(x, y);
    output[i][i] = a;
    return a;
}
int memo(int n, int *weight, int *value, int mw)
{
    int **output = new int *[n];
    for (int i = 0; i < n; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    return memo_helper(n, weight, value, mw, output, 0);
}
int rec(int n, int *weight, int *value, int mw)
{
    // base case
    if (n == 0 || mw == 0)
    {
        return 0;
    }

    // checking the 1st value
    if (weight[0] > mw)
    {
        return rec(n - 1, weight + 1, value + 1, mw);
    }

    // recursive calls
    int x = rec(n - 1, weight + 1, value + 1, mw - weight[0]) + value[0];
    int y = rec(n - 1, weight + 1, value + 1, mw);

    return max(x, y);
}

int main()
{
    int n = 4;
    int weight[n] = {1, 2, 4, 5};
    int value[n] = {5, 4, 8, 6};
    int mw = 5;

    cout << "Recursion approach : " << rec(n, weight, value, mw) << endl;
    cout << "Memoization approach : " << memo(n, weight, value, mw) << endl;
    cout << "Dp approach : " << dp(n, weight, value, mw) << endl;
    return 0;
}