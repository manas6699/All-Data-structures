#include <bits/stdc++.h>
#include "tree_class.h"
using namespace std;

tree_node<int> *take_input_level_wise()
{
    int root_data;
    cout << "Enter root data :  ";
    cin >> root_data;
    tree_node<int> *root = new tree_node<int>(root_data);

    queue<tree_node<int>*> pending_nodes;

    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        tree_node<int> *front = pending_nodes.front();
        pending_nodes.pop();
        cout << "Enter the number of children of " << front->data << " : ";
        int num_child;
        cin >> num_child;
        for (int i = 0; i < num_child; i++)
        {
            int child_data;
            cout << "Enter " << i << "th child of " << front->data <<"  ";
            cin >> child_data;
            tree_node<int> *child = new tree_node<int>(child_data);
            front->children.push_back(child);
            pending_nodes.push(child);
        }
    }
    return root;
}
void print_tree(tree_node<int> *root)
{

    // edge case
    if (root == NULL)
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

    tree_node<int>* root = take_input_level_wise();
    print_tree(root);

    // todo : delete the tree

    return 0;
}