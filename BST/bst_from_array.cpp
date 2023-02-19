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

// binary_tree_node<int> *bst_from_array(int arr[], int n, int si, int ei)
// {
//     int mid_index;
//     mid_index = n / 2;
//     if (n < 1)
//     {
//         return NULL;
//     }

//     binary_tree_node<int> *root = new binary_tree_node<int>(arr[mid_index]);
//     root->left = bst_from_array(arr, n / 2, si, mid_index - 1);
//     root->right = bst_from_array(arr, n / 2, mid_index + 1, ei);
//     return root;
// }
binary_tree_node<int>* bst_from_array(int arr[] , int si ,int ei)
{
    int size = si + ei + 1;
    int mi = size / 2;
    
    if (si > ei)
    {
        return NULL;
    }
    
    binary_tree_node<int>* root = new binary_tree_node<int>(arr[mi]);
    root->left = bst_from_array(arr,si,mi - 1);
    root->right = bst_from_array(arr , mi + 1 ,ei);
    return root;
    
}

int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    binary_tree_node<int> *p1 = bst_from_array(arr,0, n - 1);

    print_levelwise(p1);
    return 0;
}
