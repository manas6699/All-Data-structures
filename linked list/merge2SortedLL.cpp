#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

    ListNode *head = new ListNode(-1);
    ListNode *temp = head;

    while (list1 != NULL and list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    if (list1 != NULL)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    
    return head->next;
}

ListNode *take_inp()
{
    cout << "Enter linked list members : \n";
    int data;
    cin >> data;
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (data != -1)
    {
        ListNode *newListNode = new ListNode(data);
        if (head == NULL)
        {
            head = newListNode;
            tail = newListNode;
        }

        else
        {
            tail->next = newListNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(ListNode *head)
{
    cout << "Your linked-list Members are : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head1 = take_inp();
    ListNode *head2 = take_inp();

    ListNode* result = mergeTwoLists(head1, head2);
    print(result);

    return 0;
}