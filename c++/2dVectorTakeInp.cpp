#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool formularMaaKeChudi(vector<vector<int>> &matrix, int row, int col, int target)
    {
        if (target == matrix[row][col])
        {
            return true;
        }
        if (target > matrix[row / 2][col / 2])
        {
            formularMaaKeChudi(matrix, row / 2, col / 2, target);
        }
        else if (target < matrix[row / 2][col / 2])
        {
            formularMaaKeChudi(matrix, row / 2, col / 2, target);
        }
        else
        {
            return false;
        }
        
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int row = matrix.size();
        int col = matrix[0].size();

        bool answer = formularMaaKeChudi(matrix, row, col, target);
        return answer;
    }

    void print2dVector(vector<vector<int>> &v, int n, int m)
    {
        // print a 2d vector
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{

    vector<vector<int>> v;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    Solution s;
    s.print2dVector(v, n, m);
    int target;
    cin >> target;
    if (s.searchMatrix(v, target))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}