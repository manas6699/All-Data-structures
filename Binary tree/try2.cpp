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


//      1 2 -1 -1 3 -1 -1
//      1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
//      8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

pair<int , int> manas(binary_tree_node<int> *root)
{
    if (root == NULL)
    {
        pair<int , int> gandu;
        gandu.first = 0;
        gandu.second = 0;
        return gandu;
    }
    pair<int , int> left_ans = manas(root->left);
    pair<int , int> right_ans = manas(root->right);
    int ld = left_ans.first;
    int rd = right_ans.first;
    int lh = left_ans.second;
    int rh = right_ans.second;

    int hight = 1 + max(lh , rh);
    int diametere = max((lh + rh) , max(ld , rd));
    pair<int , int> ans;
    ans.first = diametere;
    ans.second = hight;

    return ans;

    
}
int main()
{

    binary_tree_node<int> *p1 = take_input_levelwise();

    print_levelwise(p1);
    cout << "Diametere of the binary tree is : " << manas(p1).first;    
    return 0;
}
