#include <bits/stdc++.h>
using namespace std;

int min_step_3(int n)
{
    int *arr = new int[n + 1];
   
    arr[1] = 0;

    int x ;
    int y = INT_MAX;
    int z = INT_MAX;
    
    for (int i = 2; i <= n; i++)
    {
        x = arr[i - 1];

        if (i % 2 == 0)
        {
            y = arr[i / 2];
        }
        if (i % 3 == 0)
        {
            z = arr[i / 3];
        }
        arr[i] = min(x, min(y , z)) + 1;
       
    }
    
    return arr[n];
    
}

int bokachodar_gare_bari_helper(int n, int arr[])
{
    // base case
    if (n <= 1)
    {
        return 0;
    }
    // small calculation
    if (arr[n] != -1)
    {
        return arr[n];
    }
    int y = INT_MAX;
    int z = INT_MAX;
    int x = bokachodar_gare_bari_helper(n - 1, arr);
    if (n % 2 == 0)
    {
        y = bokachodar_gare_bari_helper(n / 2, arr);
    }
    if (n % 3 == 0)
    {
        y = bokachodar_gare_bari_helper(n / 3, arr);
    }

    int ans = min(x, min(y, z)) + 1;
    // save korte hobe to re garmarani
    arr[n] = ans;
    
    return ans;
}

int min_step_2(int n)
{
    int *arr = new int[n + 1];

   
    
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    return bokachodar_gare_bari_helper(n, arr);
}

int min_stepto1(int n)
{
    int x = INT_MAX;
    int y = INT_MAX;

    if (n <= 1)
    {
        return 0;
    }
    int z = min_stepto1(n - 1);

    if (n % 2 == 0)
    {
        x = min_stepto1(n / 2);
    }
    if (n % 3 == 0)
    {
        y = min_stepto1(n / 3);
    }

    int ans = min(z, min(x, y)) + 1;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << "Min steps for recursion : " << min_stepto1(n) << endl;
    cout << "Min steps for memoization : " << min_step_2(n) << endl;
   
    cout << "Min steps for DP : " << min_step_3(n) << endl;

    return 0;
}