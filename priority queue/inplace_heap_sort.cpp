#include <bits/stdc++.h>
using namespace std;

void inplaceHeapSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int child_index = i;
        while (child_index > 0)
        {
            int parent_index = (child_index - 1) / 2;
            if (arr[parent_index] > arr[child_index])
            {
                swap(arr[parent_index], arr[child_index]);
            }
            else
            {
                break;
            }
            child_index = parent_index;
        }
    }
    // remove elements

    int size = n;
    while (size > 1)
    {
        swap(arr[0], arr[size - 1]);
        size--;
        int pi = 0;
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;

        while (lci < size)
        {
            int min_index = pi;
            if (arr[lci] < arr[min_index])
            {

                min_index = lci;
            }
            if ((rci < size) && (arr[rci] < arr[min_index]))
            {
                min_index = rci;
            }
            if (min_index == pi)
            {
                break;
            }

            swap(arr[pi], arr[min_index]);

            pi = min_index;
            lci = 2 * pi + 1;
            rci = 2 * pi + 2;
        }
    }
}

int main()
{
    int n = 5;
    int arr[n] = {5, 8, 3, 1, 6};
    inplaceHeapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}