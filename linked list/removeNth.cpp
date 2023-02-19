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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count == n)
    {
        head = head->next;
        return head;
    }
    temp = head;
    for (int i = 0; i < count - n - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
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
    ListNode *head = take_inp();
    cout << "Your Linked List is : " << endl;
    print(head);
    int n;
    cout << "Enter the node you want to remove : " << endl;
    cin >> n;
    ListNode *ans = removeNthFromEnd(head, n);
    print(ans);

    return 0;
}