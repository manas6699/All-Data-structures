#include <bits/stdc++.h>
using namespace std;

class stackUsingArray
{
    int *data;
    int next_index;
    int capacity;

public:
    stackUsingArray(int totalsize)
    {
        data = new int[totalsize];
        next_index = 0;
        capacity = totalsize;
    }

    // return the number of elements present in the stack
    int size()
    {
        return next_index;
    }

    bool isEmpty()
    {
        // if (next_index == 0)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }

        return next_index == 0;
    }

    // insert element

    void push(int element)
    {
        if (next_index == capacity)
        {
            cout << "stack overflow\n";
            return;
        }

        data[next_index] = element;
        next_index++;
    }

    // delete element

    int pop()
    {
        if (next_index == 0)
        {
            return INT_MIN;
        }

        next_index--;
        return data[next_index];
    }

    //top
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return INT_MIN;
        }

        return data[next_index - 1];
    }
};
