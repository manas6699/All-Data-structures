#include <iostream>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node <T> *next;

    node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class queuef
{
    node<T> *head;
    node<T> *tail;
    int size;

public:
    queuef()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int get_size()
    {
        return size;
    }

    bool is_empty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(T element)
    {
        node<T> *newnode = new node<T>(element);
        if (is_empty())
        {
            head = newnode;
            tail = newnode;
            cout << "empty queue !\n";
            //return;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }

        size++;
    }

    T front()
    {
        if (is_empty())
        {
            return 0;
        }

        return head->data;
    }

    T dequeue()
    {
        if (is_empty())
        {
            return 0;
        }
        else
        {
            T ans = head->data;
            node<T> *temp = head;
            head = head->next;
            delete temp;
            size--;
            return ans;
        }
    }
};
