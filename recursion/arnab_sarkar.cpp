#include <bits/stdc++.h>
using namespace std;

int c = 0;
int arnab(int n, int m)
{
    //static int c = 0;

    if (n % m == 0)
    {
        c += 1;
        //return c;
    }

    return c;
}

int main()
{
    int t , n , m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
    }

    cout << arnab(n, m) << endl;
    return 0;
}