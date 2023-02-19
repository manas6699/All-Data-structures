#include <bits/stdc++.h>
using namespace std;

void intersection(int arr1[], int n, int arr2[], int m)
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

    vector<int> finalAns;

    if (n > m)
    {
        for (int i = 0; i < m; i++)
        {
            if (ans1[arr2[i]])
            {
                finalAns.push_back(arr2[i]);
            }
        }
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (ans2[arr1[j]])
            {
                finalAns.push_back(arr1[j]);
            }
        }
    }
    cout << "size of the output is : " << finalAns.size() << endl;
    cout << "output : ";

    for (int k = 0; k < finalAns.size(); k++)
    {
        cout << finalAns.at(k) << " ";
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr1[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        int m;
        cin >> m;

        int arr2[m];

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        intersection(arr1, n, arr2, m);

        cout << endl;
    }

    return 0;
}
/*

2
6
2 6 8 5 4 3
4
2 3 4 7
2
10 10
1
10


*/
