#include <bits/stdc++.h>
using namespace std;
template <typename T>
class binary_tree_node
{
public:
    T data;
    binary_tree_node *left;
    binary_tree_node *right;

    binary_tree_node(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binary_tree_node()
    {
        delete left;
        delete right;
    }
};

binary_tree_node<int> *take_input_levelwise()
{
    int root_data;
    cout << "Enter root & corrosponding left & righ data simultaneously : ";
    cin >> root_data;

    if (root_data == -1)
    {
        return NULL;
    }

    binary_tree_node<int> *root = new binary_tree_node<int>(root_data);
    queue<binary_tree_node<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        binary_tree_node<int> *front = pending_nodes.front();
        pending_nodes.pop();

        int left_child;
        //cout << "Enter left child of " << front->data << " : ";
        cin >> left_child;
        if (left_child != -1)
        {
            binary_tree_node<int> *child = new binary_tree_node<int>(left_child);
            front->left = child;
            pending_nodes.push(child);
        }
        int right_child;
       // cout << "Enter right child of " << front->data << " : ";
        cin >> right_child;
        if (right_child != -1)
        {
            binary_tree_node<int> *child = new binary_tree_node<int>(right_child);
            front->right = child;
            pending_nodes.push(child);
        }
    }

    return root;
}


void print_levelwise(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        return ;
    }
    
    queue<binary_tree_node<int>*> pintu;
    pintu.push(root);
    while (pintu.size() != 0)
    {
        binary_tree_node<int> *bk = pintu.front();
        pintu.pop();
        cout << bk->data << " : " ;
        if (bk->left != NULL)
        {
            cout << "L" << bk->left->data << " ";
            pintu.push(bk->left);
        }
        if (bk->right != NULL)
        {
            cout << "R" << bk->right->data << " ";
            pintu.push(bk->right);
        }
        
        cout << endl;
    }
    
}

class my_trio
{
    public:
        bool b1;
        int maximum;
        int minimum;
};

my_trio check_bst_better(binary_tree_node<int>* root)
{
    if (root == NULL)
    {
        my_trio output;
        output.b1 = true;
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        return output;
    }
    my_trio left_output = check_bst_better(root->left);
    my_trio right_output = check_bst_better(root->right);

    int minimum = min(root->data , min(left_output.minimum , right_output.minimum));
    int maximum = max(root->data , max(left_output.maximum , right_output.maximum));

    bool final_result = (root->data > left_output.maximum) && (root->data <= right_output.maximum)
    && (left_output.b1) && (right_output.b1);

    my_trio t1;
    t1.maximum = maximum;
    t1.minimum = minimum;
    t1.b1 = final_result;
    return t1;
    
}

//      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

int main()
{

    binary_tree_node<int> *p1 = take_input_levelwise();

    print_levelwise(p1);
    my_trio m1 = check_bst_better(p1);
    if (m1.b1)
    {
        cout << "It's a bst!";
    }
    else
    {
        cout << "Not a bst";
    }
    
    return 0;
}

