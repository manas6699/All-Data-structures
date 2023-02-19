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

vector<int> *path_root2node(binary_tree_node<int> *root, int n)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (n == root->data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *left_output = path_root2node(root->left, n);
    if (left_output != NULL)
    {
        left_output->push_back(root->data);
        return left_output;
    }
    vector<int> *right_output = path_root2node(root->right, n);
    if (right_output != NULL)
    {
        right_output->push_back(root->data);
        return right_output;
    }
    else
    {
        return NULL;
    }
}

int main()
{

    binary_tree_node<int> *p1 = take_input_levelwise();

    print_levelwise(p1);
    int n;
    cout << "Enter the value you want to trace the path : ";
    cin >> n;
    vector<int> *output = path_root2node(p1, n);
    //      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    for (int i = 0; i < output->size(); i++)
    {
        cout << output->at(i) << " - ";
    }
    delete output;
    return 0;
}
