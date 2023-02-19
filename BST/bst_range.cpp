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

//     8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

void bst_range(binary_tree_node<int> *root, int x, int y)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= x && root->data <= y)
    {
        cout << root->data << " ";
    }
    if (x <= root->data)
    {
        bst_range(root->left, x, y);
    }
    if (y >= root->data)
    {
        bst_range(root->right, x, y);
    }
}

int main()
{

    binary_tree_node<int> *p1 = take_input_levelwise();

    print_levelwise(p1);
    cout << "For finding the range defy the range : ";
    int x, y;
    cin >> x >> y;
    bst_range(p1 , x ,y);
    return 0;
}
