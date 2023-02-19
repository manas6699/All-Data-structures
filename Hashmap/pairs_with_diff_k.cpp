#include <bits/stdc++.h>
using namespace std;

void pairs_with_diff_k(int input[], int n, int k)
{
    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[input[i]]++;
        cout << "inputs : " << m[input[i]] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        int key = input[i];

        if (k == 0)
        {
            int a = m[key];
            int count = ((a - 1) * a) / 2;
            while (count > 0)
            {
                cout << key << " " << key << endl;
                count--;
            }
        }

        else
        {
            int a = key + k;
            int b = key - k;

            int count = m[key];
            int count1 = m[a];
            int count2 = m[b];

            for (int i = 0; i < count * count1; i++)
            {
                cout << min(a, key) << " " << max(a, key) << endl;
            }

            for (int i = 0; i < count * count2; i++)
            {
                cout << min(b, key) << " " << max(b, key) << endl;
            }
        }
        m.erase(key);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements in the array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter the value of K  : ";
    cin >> k;
    pairs_with_diff_k(arr, n, k);

    return 0;
}