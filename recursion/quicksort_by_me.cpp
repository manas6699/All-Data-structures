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
    int pivot = arr[l];
    int i = l;
    int j = h;

    do
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        swap(&arr[i], &arr[j]);

    } while (i < j);
    swap(&arr[l], &arr[j]);
    return j;
}
void quicksort(int arr[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(arr, l, h);
        quicksort(arr, l, j);
        quicksort(arr, j + 1, h);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements \n";
    cin >> n;
    int arr[n];
    /* input
   10
99 55 66 33 551 54 4 84 690 61 
 */
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quicksort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}