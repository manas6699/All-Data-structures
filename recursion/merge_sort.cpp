#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}
int main()
{
    int n = 5;
    int arr[n];

    arr[0] = 5;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 1;
    cout << "Before sorting : " << endl;
     for (int i = 0; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    merge_sort(arr, 0, 4);
    cout << "After sorting : " << endl;
    for (int i = 0; i < n ; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}