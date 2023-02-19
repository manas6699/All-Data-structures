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

void print_binary_tree(binary_tree_node <int> *root)
{
    if (root == NULL)
    {
        return;
    }
    
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L " << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R " << root->right->data << " ";
    }

    
    
    cout << endl;

    
    print_binary_tree(root->left);
    print_binary_tree(root->right);

}

int main()
{
    binary_tree_node <int>* root = new binary_tree_node<int>(1);
    binary_tree_node <int>* n1 = new binary_tree_node<int>(2);
    binary_tree_node <int>* n2 = new binary_tree_node<int>(3);
    binary_tree_node <int>* n3 = new binary_tree_node<int>(40);
    binary_tree_node <int>* n4 = new binary_tree_node<int>(50);

    root->left = n1;
    root->right = n2;
    n1->left = n3;

    n1->right = n4;

     
    
    print_binary_tree(root);
    return 0;
}

