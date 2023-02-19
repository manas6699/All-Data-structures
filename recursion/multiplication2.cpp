#include <bits/stdc++.h>
using namespace std;

int mult(int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (m == 1)
    {
        return n;
    }
    int gandu = mult(m, n - 1);
    return m + gandu;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << mult(m, n);

    return 0;
}