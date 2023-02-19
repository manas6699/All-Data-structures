#include <bits/stdc++.h>
using namespace std;

int dp(string s, string t)
{
    // dynamically allocate a 2-D array
    int m = s.size();
    int n = t.size();

    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }
    // fill 1st row
    for (int j = 0; j <= n; j++)
    {
        output[0][j] = 0;
    }
    // fill 1st column
    for (int i = 1; i <= m; i++)
    {
        output[i][0] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // check if 1st element matches
            if (s[m - i] == t[n - j])
            {
                output[i][j] =  output[i - 1][j - 1];
            }
            else
            {
                int a = output[i][j - 1] + 1;
                int b = output[i - 1][j] + 1;
                int c = output[i - 1][j - 1] + 1;
                output[i][j] = min(a, min(b, c));
            }
        }
    }

    return output[m][n];
}

int memo_helper(string s , string t , int** output)
{
    int m = s.size();
    int n = t.size();
    // base case
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size() , t.size());
    }
    // check if answer alredy exists
    if (output[m][n] != -1)
    {
        return output[m][n];
    }
    int ans;
    // recursive calls
    if (s[0] == t[0])
    {
        ans =  memo_helper(s.substr(1), t.substr(1), output);
    }
    else
    {
        int a = memo_helper(s.substr(1), t, output) + 1;
        int b = memo_helper(s, t.substr(1), output) + 1;
        int c = memo_helper(s.substr(1), t.substr(1), output) + 1;
        ans = min(a, min(b, c));
    }

    output[m][n] = ans;
    return ans;
}

int memo(string s , string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }
    return memo_helper(s, t, output);
}

int rec(string s , string t)
{
    // base case
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size() , t.size());
    }

    // recursive calls
    if (s[0] == t[0])
    {
        return  rec(s.substr(1) , t.substr(1));
    }
    int a = rec(s , t.substr(1)) + 1;
    int b = rec(s.substr(1) , t) + 1 ;
    int c = rec(s.substr(1) , t.substr(1)) + 1 ;

    return min(a , min(b , c));
    
}

int main()
{
    string s , t;
    cin >> s >> t;

    cout << "Recursion approach : " << rec(s , t) << endl;
    cout << "Memoization approach : " << memo(s, t) << endl;
    cout << "Dp approach : " << dp(s, t) << endl;


    return 0;
}