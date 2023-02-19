#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int l, int h)
{
    int m = arr[l];
    int i = l;
    int j = h;

    do
    {
        do
        {
            i++;
        } while (arr[i] <= m);

        do
        {
            j--;
        } while (arr[j] > m);

    } while (i < j);
    swap(&arr[l], &arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pivot = partition(arr, l, h);
    }
}

int main()
{
    int n;
    cout << "Enter number\n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}