

/*          brute force

                    method

                                */

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
        // cout << "Enter left child of " << front->data << " : ";
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
        return;
    }

    queue<binary_tree_node<int> *> pintu;
    pintu.push(root);
    while (pintu.size() != 0)
    {
        binary_tree_node<int> *bk = pintu.front();
        pintu.pop();
        cout << bk->data << " : ";
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

//      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

int maximum(binary_tree_node<int>* root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data , max(maximum(root->left) , maximum(root->right)));
    
}

int minimum(binary_tree_node<int>* root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data , min(minimum(root->left) , minimum(root->right)));
    
}



bool check_bst(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int left_max = maximum(root->left);
    int right_min = minimum(root->right);

    bool result = (root->data > left_max) && (root->data < right_min) && (check_bst(root->left)) && check_bst(root->right);
    return result;
}

int main()
{

    binary_tree_node<int> *p1 = take_input_levelwise();

    print_levelwise(p1);
    if (check_bst(p1))
    {
        cout << "Its a bst!";
    }
    else
    {
        cout << "This is a normal tree!";
    }
    
    return 0;
}

/*          brute force

                    method

                                */