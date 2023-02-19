// honor's method for tailor series
#include <bits/stdc++.h>
using namespace std;

double e(int x , int n)
{
    static double result = 1;
    if(n == 0)
    {
        return result;
    }
    // for ( ; n > 0; n--)
    // {
    //     result = 1 + x / n * result;
    // }
    result = 1 + x * result / n;
    return e(x , n - 1);
    
}

int main()
{
    
   // cout << e(1 , 10);
   printf("%lf" ,e(1 , 10) );
    return 0;
} 