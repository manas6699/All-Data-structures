// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int m;
//     cin >> m;
//     int temp = m;
//     int count = 0;
//     while (m % 10 != 0)
//     {
//         m = m / 10;
//         count++;
//     }
//     //cout << count <<endl;

//     for (int i = 0; i < count; i++)
//     {
//         cout << pow((temp % 10) ,3)  << " ";
//         temp = temp / 10;
        
//     }
    
    
//     return 0;
// }



#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int dummy = n, sum = 0;

    while (dummy != 0)
    {
        int last = dummy % 10;

        cout << "Last = " << last;

        int cube = pow(last, 3);

        cout << " " << last << "^3 = " << cube << endl;

        sum += cube;

        dummy /= 10;
    }

    if (sum == n)
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }

    return 0;
}