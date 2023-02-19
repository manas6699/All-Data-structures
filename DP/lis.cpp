#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n)
{
    int *output = new int[n];
    output[0] = 1;
    for (int i = 1; i < n; i++)
    {
        output[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                continue;
            }

            int possible_ans = output[j] + 1;
            if (possible_ans > output[i])
            {
                output[i] = possible_ans;
            }
        }
    }
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        if (best < output[i])
        {
            best = output[i];
        }
    }

    return best;
}
int main()
{
    int n;
    cout << "Enter the size of the array : " << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Apperent direct dp approach : " << lis(arr, n) << endl;
    return 0;
}