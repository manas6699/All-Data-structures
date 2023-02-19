#include <bits/stdc++.h>
using namespace std;
int i = 1;
int min_count(int n)
{

    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int minimum = INT_MAX;

    int count = min_count(n - (i * i));
    i++;
    minimum = min(minimum, count);
    

    return minimum + 1;
}

int main()
{
    int n;
    cin >> n;
    int i = 0;
    cout << "Recursive approach : " << min_count(n) << endl;

    return 0;
}