#include <bits/stdc++.h>
#include "tree_class.h"
using namespace std;

int main()
{
    tree_node<int> *root = new tree_node<int>(1);
    tree_node<int> *node1 = new tree_node<int>(2);
    tree_node<int> *node2 = new tree_node<int>(3);

    root->children.push_back(node1); 
    root->children.push_back(node2); 

    return 0;
}