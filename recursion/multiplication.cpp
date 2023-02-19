#include <bits/stdc++.h>
using namespace std;

int multiplication (int m , int n){
    if(n == 1){
        return m;
    }

    if(n == 2){
        return m + m;
    }

    return multiplication(m ,n - 1);
    
}

int main()
{
    int m , n;
    cin >> m >> n;

    cout << multiplication(m , n);

    return 0;
}