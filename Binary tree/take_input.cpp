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

binary_tree_node <int>* take_input()
{
    int root_data;
    cout << "Enter data : ";
    cin >> root_data;

    if (root_data == -1)
    {
        return NULL;
    }

    binary_tree_node<int>* root = new binary_tree_node<int>(root_data);
    binary_tree_node<int>* left_child = take_input();
    binary_tree_node<int>* right_child = take_input();

    root->left = left_child;
    root->right = right_child;


    return root;
    


} 

void print_binary_tree(binary_tree_node <int> *root)
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
    
    binary_tree_node<int>* p1 = take_input();
     
    
    print_binary_tree(p1);
    return 0;
}

