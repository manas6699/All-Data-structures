// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     cout << " Hello world ";
//     int a = 5 ;
//     int b = 6;
//     cout << a * b;
//     return 0;
// }

#include <iostream>

using namespace std;

int f(int x, int *py, int **ppz)
{
    int y, z;

    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;

    return x + y + z;
}

int main()
{
    int c, *b, **a;

    c = 4;
    b = &c;
    a = &b;

    cout << f(c, b, a);

    return 0;
}