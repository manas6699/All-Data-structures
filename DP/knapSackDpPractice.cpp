#include <bits/stdc++.h>
using namespace std;

int dp(int n , int* weight , int* value , int mw)
{
    // n+1 ar w+1 size er 2d vector nilam
    vector<vector<int>> takenArray(n + 1 , vector<int>(mw + 1));
    // build the table
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= mw; w++)
        {
            if (i == 0 || w == 0)
            {
                takenArray[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                takenArray[i][w] = max(value[i - 1] + takenArray[i - 1][w - weight[i - 1]] ,takenArray[i - 1] [w] );

            }
            else
            {
                takenArray[i][w] = takenArray[i - 1][w];
            }
            
        }
        
    }

    return takenArray[n][mw];
    
}

int main()
{
    int n = 4;
    int weight[n] = {1, 2, 4, 5};
    int value[n] = {5, 4, 8, 6};
    int mw = 5;

    cout << dp(n , weight , value , mw);

    return 0;
}