#include <bits/stdc++.h>
using namespace std;

void longest_subset_zero(int arr[], int n)
{
    int max_len = 0;
    int sum = 0;
    unordered_map<int, bool> m1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0 && max_len == 0)
        {
            max_len = 1;
        }
        if (sum == 0)
        {
            max_len = i + 1;
        }

        if (m1.find(sum) != m1.end())
        {
            max_len = max(max_len, i - m1[sum]);
        }
        else
        {
            m1[sum] = i;
        }
    }

    cout << "Maximum subset length of sum zero is : " << max_len;
}

int main()
{
    int n = 10;
    int arr[n] = {95 ,-97 ,-387 ,-435 ,-5 ,-70, 897, 127 ,23 ,284};

    longest_subset_zero(arr, n);

    return 0;
}