#include <bits/stdc++.h>
using namespace std;

void Toh (int n , int a ,int b , int c)
{
    if (n > 0)
    {
        Toh(n - 1 ,a , c , b);
        cout << a << " To " << c <<endl;
        Toh(n - 1, b , a , c);
    }
}

int main()
{
    int n , a , b , c ;
    cin >> n;
    a = 1;
    b = 2;
    c = 3;

    Toh(n , a , b , c);
    return 0;
}