#include <bits/stdc++.h>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node<T> *next;

    node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class stack_use
{
    node<T> *head;
    int size;

public:
    stack_use()
    {
        head = NULL;
        size = 0;
    }

    int sizet()
    {
        return size;
    }

    void push(int element)
    {
        node<T> *newnode = new node<T>(element);
        newnode->next = head;
        head = newnode;
        size++;
    }
    bool is_empty()
    {
        return size == 0;
    }

    T pop()
    {

        if (is_empty())
        {
            return 0;
        }

        T ans = head->data;
        node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    T top()
    {
        if (is_empty())
        {
            return 0;
        }

        return head->data;
    }
};
