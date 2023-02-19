#include <bits/stdc++.h>
using namespace std;

int rec(int sum ,int x, int b)
{
    int curr = pow(x , b);
    // base case
    if (curr > sum)
    {
        return 0;
    }
    if (curr == sum)
    {
        return 1;
    }
    
    // recursive calls
    int ans = rec(sum - curr , x + 1 , b) + rec(sum ,x + 1 , b);
    return ans;
}

int main()
{
    int a, b;
    a = 100; b = 2;
    int x = 1;
    cout << "Recursion result : " << rec(a , x , b) << endl;
    return 0;
}