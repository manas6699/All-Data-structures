#include <bits/stdc++.h>
using namespace std;

void mergeSortedHalves(int arr[], int si, int mid, int ei)
{
    int n1 = mid - si + 1;
    int n2 = ei - mid;

    int temp1[n1];
    int temp2[n2];

    for (int i = 0; i < n1; i++)
    {
        temp1[i] = arr[si + i];
    }

    for (int i = 0; i < n2; i++)
    {
        temp2[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = si;

    while (i < n1 && j < n2)
    {
        if (temp1[i] < temp2[j])
        {
            arr[k] = temp1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = temp2[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = temp1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int si, int ei)
{
    if (si < ei)
    {
        int mid = (si + ei) / 2;

        mergeSort(arr, si, mid);
        mergeSort(arr, mid + 1, ei);

        mergeSortedHalves(arr, si, mid, ei);
    }
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

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}