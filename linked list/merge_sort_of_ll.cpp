#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

node *take_inp()
{
    cout << "Enter linked list members : \n";
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;

    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }

        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(node *head)
{
    cout << "Your linked-list Members are : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *mid_of_ll(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
       
        
        slow = slow->next;
        fast = fast->next->next;


    }
    return slow;
}

node *merge(node *left , node *right)
{
    node *result = NULL;
    if(left == NULL)
    {
        return right;

    }

    if(right == NULL)
    {
        return left;
    }

    if(left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next , right);
    }

    else
    {
        result = right;
        result->next = merge(left , right->next);
    }
    return result;
}


node *merge_sort(node *head)
{
    cout << "\nreached here";
    node *temp = head;
    if(temp == NULL || temp->next == NULL)
    {
        return head;
    }

    node *middle = mid_of_ll(temp);
    node *next_of_middle = middle->next;
    middle->next == NULL;

    node *left = merge_sort(temp);
    node *right = merge_sort(next_of_middle);

    node *sorted_list = merge(left , right);

    return sorted_list;
}




int main()
{
    node *head = take_inp();
    print(head);

    node *d = mid_of_ll(head);
    cout << "Middle of the linked list is : " << d->data;
    
    cout << "hi";

    node *temp1 = head;
    cout << "hi";
    cout << merge_sort(temp1); // wrong!
    cout << "hi";
    cout << "Your sorted linked  list is : ";
    //print(temp1);
    cout << temp1->data << " ";
    return 0;
}