// Largest BST

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

class BSTreturn
{

public:
    int min, max, height;
    bool isBST;
};

BSTreturn helper(binary_tree_node<int> *root)
{
    if (root == NULL)
    {

        BSTreturn ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.height = 0;
        ans.isBST = true;
        return ans;
    }

    BSTreturn Left = helper(root->left);
    BSTreturn Right = helper(root->right);

    if ((Left.isBST == false) && (Left.max < root->data))
    {
        Left.isBST = false;
    }

    if ((Right.isBST == false) && (Right.min > root->data))
    {
        Right.isBST = false;
    }

    if (!Left.isBST || !Right.isBST || root->data > Right.min || root->data < Left.max)
    {
        if (Left.height > Right.height)
        {
            Left.isBST = false;
            return Left;
        }

        else
        {
            Right.isBST = false;
            return Right;
        }
    }
    BSTreturn ans;
    ans.isBST = true;
    ans.min = min(Left.min, min(root->data, Right.min));
    ans.max = max(Left.max, max(root->data, Right.max));
    ans.height = max(Left.height, Right.height) + 1;
    return ans;
}
//      5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

binary_tree_node<int> *take_input_levelwise()
{
    int root_data;
    cout << "Enter root & corrosponding left & right data simultaneously : ";
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

int main()
{

    binary_tree_node<int> *root = take_input_levelwise();

    print_levelwise(root);
    BSTreturn final_ans = helper(root);
    int a = final_ans.height;
    cout << "Largest BST is : " << a;

    return 0;
}
//      5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
