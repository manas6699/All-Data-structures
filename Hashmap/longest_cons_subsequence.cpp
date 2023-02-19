#include <bits/stdc++.h>
using namespace std;

void longest_subsequence(int arr[], int n)
{
    unordered_map<int, bool> map;
    pair<int, int> final_ans;

    for (int i = 0; i < n; i++)
    {
        map[arr[i]] = true;
    }
    int start = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++)
    {
        int curr_element = arr[i];
        int temp_len = 1;

        while (map.count(curr_element + 1) > 0)
        {
            temp_len++;
            curr_element++;
        }
        curr_element = arr[i];

        while (map.count(curr_element - 1) > 0)
        {
            temp_len++;
            curr_element--;
        }
        if (temp_len > max_len)
        {
            max_len = temp_len;
            start = curr_element;
        }

        if (temp_len == max_len && temp_len != 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == start)
                {
                    break;
                }
                else if (arr[i] == curr_element)
                {
                    start = curr_element;
                    break;
                }
                
                
            }
            
        }
        

        final_ans.first = start;
        final_ans.second = (start + max_len ) - 1;
    }

    cout << final_ans.first << endl;
    cout << final_ans.second << endl;
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
    longest_subsequence(arr, n);

    return 0;
}