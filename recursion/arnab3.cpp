#include <iostream>

using namespace std;

int mul(int a, int b)
{
    if(a == 0 || b == 0)
    {
        return 0;
    }
    if(a == 1 )
    {
        return b;
    }
    
    int smallOutput = mul((a), (b - 1));
    
    return  a + smallOutput;
}

int main()
{
    int a, b;
    
    cout << "Enter two numbers = ";
    cin >> a >> b;
    
    cout << a << " x " << b << " = " << mul(a, b);

    return 0;
}