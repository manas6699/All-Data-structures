#include <bits/stdc++.h>
using namespace std;

int ncr(int n , int r)
{
    if(r == 0 || n == r)
    {
        return 1;
    }
    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}

int main()
{
    cout << ncr(6,2);

    return 0;
}