#include <bits/stdc++.h>
using namespace std;

int zeroCount (int a){
    static int count{};
    
    if (a / 10 == 0){
        return 0;
    }
    if (a % 10 == 0){
        count += 1;
    }
    zeroCount(a/10);
    return count;

}

int main()
{
    double a;
    cin >> a;

    cout << zeroCount(a);
    return 0;
}