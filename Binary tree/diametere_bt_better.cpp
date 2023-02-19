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

class my_pair
{
public:
    int a;
    int b;
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

//      1 2 -1 -1 3 -1 -1
//      1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
//      8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
my_pair height_diameter(binary_tree_node<int> *root)
{
    

    if (root == NULL)
    {
        my_pair ans;
        ans.a = 0;
        ans.b = 0;
        return ans;
    }
    my_pair left_data = height_diameter(root->left);
    my_pair right_data = height_diameter(root->right);

    int left_dia = left_data.a;
    int left_height = left_data.b;
    int right_dia = right_data.a;
    int right_height = right_data.b;

    int h = 1 + max(left_height, right_height);
    int d = max(left_height + right_height, max(left_dia, right_dia));

    my_pair p;
    p.a = h;
    p.b = d;
    return p;
}
int main()
{

    binary_tree_node<int> *p1 = take_input_levelwise();

    print_levelwise(p1);
    cout << "Diametere of the binary tree is : " ;
    my_pair f_ans;
    f_ans = height_diameter(p1);
    cout << f_ans.b;
    return 0;
}
