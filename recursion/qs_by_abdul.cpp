// #include <stdio.h>
// #include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}
void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}
int main()
{
    // int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    // QuickSort(A,0, n);
    // for (i = 0; i < 10; i++)
    //     printf("%d ", A[i]);
    // printf("\n");
    // return 0;
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

    QuickSort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}