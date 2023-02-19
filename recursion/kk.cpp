#include <bits/stdc++.h>
using namespace std;

void kk(int n)
{
    if (n == 1)
    {
        return;
    }
    if (n % 2 == 0)
    {
        n = n / 2;
        cout << n << " ";
        kk(n);
    }
    else
    {
        n = (n * 3) + 1;
        cout << n << " ";
        kk(n);
    }
}

int main()
{
    int n;
    cin >> n;

    cout << n <<" ";

    kk(n);

    return 0;
}