#include <bits/stdc++.h>
#include "tree_class.h"
using namespace std;

tree_node<int>*take_input()
{
    int root_data;
    cout << "Enter data :";
    cin >> root_data;
    tree_node<int>* root = new tree_node<int>(root_data);

    int n;
    cout << "Enter the number of children of   " << root_data << " : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        tree_node<int>* child = take_input();
        root->children.push_back(child);
    }

    return root;

}
void print_tree(tree_node <int> *root)
{

    // edge case
    if(root == NULL)
    {
        cout << "no members in the tree!!\n";
        return;
    }
    
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";

    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print_tree(root->children[i]);
    }
    
}

int main()
{
    // tree_node<int> *root = new tree_node<int>(1);
    // tree_node<int> *node1 = new tree_node<int>(2);
    // tree_node<int> *node2 = new tree_node<int>(3);

    // root->children.push_back(node1); 
    // root->children.push_back(node2);


    tree_node<int>* root = take_input();
    print_tree(root);

    // todo : delete the tree 


    return 0;
}