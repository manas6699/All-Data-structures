#include <bits/stdc++.h>
using namespace std;

//void merge(int , int , int , int);
void merge(int arr[], int si, int ei, int mi)
{
    int n1 = mi - si + 1;
    int n2 = ei - mi;

    int temp1[n1];
    int temp2[n2];

    for (int i = 0; i < n1; i++)
    {
        temp1[i] = arr[si + i];
    }
    for (int i = 0; i < n2; i++)
    {
        temp2[i] = arr[mi + 1 + i];
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
void sort(int arr[], int si, int ei)
{
    if (si < ei)
    {
        int mi = (si + ei) / 2;

        sort(arr, si, mi);
        sort(arr, mi + 1, ei);
        merge(arr, si, ei, mi);
    }
}

int main()
{
    int n;
    cout << "Enter number \n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
