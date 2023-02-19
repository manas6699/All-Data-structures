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
    cout << "Enter root data : ";
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
        cout << "Enter left child of " << front->data << " : ";
        cin >> left_child;
        if (left_child != -1)
        {
            binary_tree_node<int> *child1 = new binary_tree_node<int>(left_child);
            front->left = child1;
            pending_nodes.push(child1);
        }
        int right_child;
        cout << "Enter right child of " << front->data << " : ";
        cin >> right_child;
        if (right_child != -1)
        {
            binary_tree_node<int> *child2 = new binary_tree_node<int>(right_child);
            front->right = child2;
            pending_nodes.push(child2);
        }
    }

    return root;
}

void print_binary_tree(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data << " ";
    }

    cout << endl;

    print_binary_tree(root->left);
    print_binary_tree(root->right);
}

//      1 2 -1 -1 3 -1 -1

int main()
{

    binary_tree_node<int> *p1 = take_input_levelwise();

    print_binary_tree(p1);
    return 0;
}
