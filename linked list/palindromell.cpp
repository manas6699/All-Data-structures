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

bool isPalindrome(node* head) {
    
    node *temp = head;
    stack<int> s;
    while(temp != NULL){
        s.push(temp->data);
        temp = temp->next;

    }
     if(s.empty()){
        return true;
     }
    while(head != NULL){
        int i = s.top();
        s.pop();
        if(head->data != i){
            return false;
        }
        head = head->next;
    }
    return true;
        
    }

node *reverse_ll(node* &head)
{
    node *temp1 = head;
    node *temp2 = head->next;

    if (head == NULL || temp2 == NULL)
    {
        return head;
    }

    reverse_ll(temp2);

    temp1->next->next = temp1;
    temp1->next = NULL;
    head = temp2;

    return head;
}

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

int main()
{
    node *head = take_inp();
    print(head);

    if(isPalindrome(head)){
        cout << "Yes, it is a palindrome";
    }
    else{
        cout << "No, it is not a palindrome";
    }

    return 0;
}