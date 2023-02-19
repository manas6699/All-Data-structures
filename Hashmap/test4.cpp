#include <bits/stdc++.h>
using namespace std;

void test(int arr2[], int n)
{
    map<int, int> m1;
    for (int i = 0; i < n; i++)
    {

        m1[arr2[i]] = i;
    }
    map<int, int>::iterator it;
    for (it = m1.begin(); it != m1.end(); ++it)
    {
        cout << (*it).first << " " << (*it).second << endl; 
        
    }
}
int main()
{
    int n = 9;
    int arr[n] = {6, 3, -1, 2, -4, 3, 1, -2, 20};

    int arr2[n] = {0};
    int pointer = 0;
    for (int i = 0; i < n; i++)
    {
        pointer += arr[i];
        arr2[i] = pointer;
        cout << arr2[i] << " ";
    }
    cout << endl;
    test(arr2, n);
    int pointr2 = 0;
    int ans = 0;
    int arr3[3] = {0};
    for (int i = 0; i < n; i++)
    {
        if (arr2[pointr2] == arr2[i + 1])
        {
            ans++;
        }
        //pointr2++;
        
        cout << ans ;
        pointr2++;
    }
    

    return 0;
}