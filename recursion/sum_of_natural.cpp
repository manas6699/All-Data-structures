#include <bits/stdc++.h>
using namespace std;

int sum(int a)
{
    if(a > 0)
    {
        return a + sum(a - 1);
    }
    //cout << " Not a valid number\n";
    return 0;
}

int main()
{
    int n;
    cin >> n;

    cout << sum(n);
    return 0;
}