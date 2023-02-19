#include <bits/stdc++.h>
using namespace std;

int x_to_the_power_n(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }

    return x_to_the_power_n(m, n - 1) * m;
}
int main()
{

    cout << x_to_the_power_n(2 , 5);

    return 0;
}