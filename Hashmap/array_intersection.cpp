#include <bits/stdc++.h>
using namespace std;

void array_intersection(int *arr1, int n, int *arr2, int m)
{
    unordered_map<int, bool> ans1;
    unordered_map<int, bool> ans2;

    for (int i = 0; i < n; i++)
    {
        if (ans1.count(arr1[i]) == 0)
        {
            ans1[arr1[i]] = true;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (ans2.count(arr2[j]) == 0)
        {
            ans2[arr2[j]] = true;
        }
    }

    vector<int> final_ans;
    if (n > m)
    {
        for (int i = 0; i < m; i++)
        {
            if (ans1[arr2[i]])
            {
                final_ans.push_back(arr2[i]);
            }
        }
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (ans2[arr1[j]])
            {
                final_ans.push_back(arr1[j]);
            }
        }
    }
    cout << "size of the output is : " << final_ans.size() << endl;
    cout << "Output : ";
    for (int l = 0; l < final_ans.size(); l++)
    {
        cout << final_ans.at(l) << " ";
    }
}

int main()
{
    int t;
    cout << "enter number of test cases : ";
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        int arr1[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr1[j];
        }
        int m;
        cin >> m;
        int arr2[m];

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        array_intersection(arr1, n, arr2, m);
        cout << endl;
    }

    return 0;
}
