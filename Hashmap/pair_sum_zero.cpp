#include <bits/stdc++.h>
using namespace std;

void pair_sum(int *arr, int n)
{
    int count = 0;
    unordered_map<int, bool> ans;
    vector<int> final_ans;
    vector<int> v1;
    // int v1[10];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            count++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            v1.push_back(arr[i] * -1);
        }
    }
    // cout << "Modified array : " << endl;
    //  for (int i = 0; i < count; i++)
    //  {
    //      cout << v1[i] << endl;
    //  }

    for (int i = 0; i < count; i++)
    {
        if (ans.count(v1[i]) == 0)
        {
            ans[v1[i]] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[arr[i]])
        {
            final_ans.push_back(arr[i]);
        }
    }

    cout << "Pairs are : " << final_ans.size() << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pair_sum(arr, n);

    return 0;
}