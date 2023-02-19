#include <bits/stdc++.h>
using namespace std;
int vargab = 1;
void print_numbers(int n)
{

    if (n <= 0)
    {
        return ;
    }

    cout << vargab << " ";
    vargab++;
    print_numbers(n - 1);
}

int main()
{
    int t;
    cin >> t;
    print_numbers(t);

    return 0;
}