#include <bits/stdc++.h>
using namespace std;
void funB(int);

void funA (int a)
{
    if(a > 0)
    {
        cout << a << endl;
        funB(a - 1);
    }
    
}

void funB(int a)
{
    if(a > 0)
    {
        funA(a / 2);
        cout << a << endl;

    }
    

}

int main()
{
    
    int a = 20;
    funA(a);
    return 0;
}