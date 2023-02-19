#include <bits/stdc++.h>
using namespace std;

class stack_use
{
    int *data;
    int capacity;
    int next_index;

public:
    stack_use()
    {
        data = new int[5];
        next_index = 0;
        capacity = 5;
    }

    void push(int element)
    {

        if (next_index == capacity)
        {
            //cout << "Stack overflow\n";
            int *newset = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newset[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newset;
        }

        data[next_index] = element;
        next_index++;
    }

    int size()
    {
        return next_index;
    }

    int top()
    {
        if (next_index == capacity)
        {
            return INT_MIN;
        }

        return data[next_index - 1];
    }

    bool is_empty()
    {
        return next_index == 0;
    }

    int pop()
    {
        if (is_empty())
        {
            return INT_MIN;
        }
        next_index--;
        return data[next_index];
    }

    
};

int main()
{
    stack_use s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.push(70);
    s1.push(80);
    s1.push(90);
    s1.push(100);
    s1.push(200);
    s1.push(300);
    s1.push(400);
    s1.push(500);
    s1.push(600);

    cout << s1.top() << endl;
    cout << s1.size() << endl;
    s1.pop();
    cout << s1.top() << endl;
    cout << s1.size() << endl;

    return 0;
}