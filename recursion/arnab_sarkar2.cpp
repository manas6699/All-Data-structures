#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m;
    int c = 0;
    cin >> t >> m;
    while (t--)
    {
        cin >> n ;
        if (n % m == 0)
        {
            c++;
        }
    }

    cout << c;

    return 0;
}