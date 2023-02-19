#include <bits/stdc++.h>
using namespace std;

int pow(int m , int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return m;
    }
    
    return m * pow(m , n - 1);
    
}

int main()
{
    int a , b;
    cin >> a >> b;

    cout << pow(a,b);
    return 0;
}