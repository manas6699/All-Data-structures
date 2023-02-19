#include <iostream>
#include <utility>
using namespace std;

void arrayInput(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void arrayPrint(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

pair<int, int*> sizeAndPointer;

pair<int, int*> takeInput()
{
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sizeAndPointer.first = n;
    sizeAndPointer.second = arr;

    return sizeAndPointer;
}