#include <bits/stdc++.h>
using namespace std;

template <typename T>

class tree_node
{
public:
    T data;
    vector<tree_node<T> *> children;

    tree_node(T data)
    {
        this->data = data;
    }
};

tree_node<int> *gandu()
{
    int root_data;
    cout << "Enter root data : ";
    cin >> root_data;

    tree_node<int> *root = new tree_node<int>(root_data);
    queue<tree_node<int> *> pending_nodes;
    pending_nodes.push(root);

    while (pending_nodes.size() != 0)
    {
        tree_node<int> *front = pending_nodes.front();
        pending_nodes.pop();

        int num_child;
        cout << "Enter the number of child of " << front->data << " : ";
        cin >> num_child;

        for (int i = 0; i < num_child; i++)
        {
            int child_data;
            cout << "Enter the " << i << " th data of " << front->data << " : ";
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
    // cout << root->data << " : ";
    // for (int i = 0; i < root->children.size(); i++)
    // {
    //     cout << root->children[i]->data <<" , ";
    // }
    // cout << endl;
    // for (int i = 0; i < root->children.size(); i++)
    // {
    //     print_tree(root->children[i]);
    // }

    // cout << root->data << " : ";
    // queue<tree_node<int> *> huntululululu;
    // huntululululu.push(root);
    // for (int i = 0; i < huntululululu.size(); i++)
    // {
    //     cout << root->children[i]->data << " , ";
    // }
    // huntululululu.pop();
    // huntululululu.push(root->children);


    queue<tree_node<int>*> piklu;
    piklu.push(root);
    while(piklu.size() != 0)
    {
        tree_node<int> *front_node = piklu.front();
        piklu.pop();
        cout << front_node->data << " : ";
        
        for (int i = 0; i < front_node->children.size(); i++)
        {
            cout << front_node->children[i]->data << " , ";
            piklu.push(front_node->children[i]);
        }

        cout << endl;
        
    }

}

int main()
{
    tree_node<int> *root = gandu();
    print_tree(root);

    return 0;
}