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

class foreplay
{
public:
    int min, max, hight;
    bool isBST;
};

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

foreplay largest_bst(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        foreplay result;
        result.max = INT_MIN;
        result.min = INT_MAX;
        result.isBST = true;
        result.hight = 0;

        return result;
    }
    foreplay left = largest_bst(root->left);
    foreplay right = largest_bst(root->right);

    if ((left.isBST == false) && (left.max < root->data))
    {
        left.isBST = false;
    }
    if ((right.isBST == false) && (right.min > root->data))
    {
        right.isBST = false;
    }

    if ((!right.isBST) || (!left.isBST) || (left.max > root->data) || (right.min < root->data))
    {
        if (left.hight > right.hight)
        {
            left.isBST = false;
            return left;
        }
        else
        {
            right.isBST = false;
            return right;
        }
    }
    foreplay final_ans;
    final_ans.isBST = true;
    final_ans.max = max(max(left.max, root->data), right.max);
    final_ans.min = min(min(right.min, root->data), left.min);
    final_ans.hight = max(right.hight, left.hight) + 1;
    return final_ans;
}

//      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

int main()
{

    binary_tree_node<int> *root = take_input_levelwise();

    print_levelwise(root);
    foreplay a = largest_bst(root);
    
    cout << "Largest BST is : " << a.hight;
    return 0;
}
//      10 8 20 6 9 18 24 -1 -1 -1 -1 -1 -1 22 -1 -1 -1