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

// taking input
tree_node <int> *take_inp()
{
    int root_data;
    cout << "Enter root data : ";
    cin >> root_data;

    tree_node<int> *root = new tree_node <int> (root_data);
    queue<tree_node<int> *> pending_nodes;
    pending_nodes.push(root);

    while (pending_nodes.size() != 0)
    {
        tree_node<int> *front = pending_nodes.front();
        pending_nodes.pop();

        int num_child;
        cout << "Enter the num of children of " << front->data << " : ";
        cin >> num_child;

        for (int i = 0; i < num_child; i++)
        {
            int child_data;
            cout << "Enter " << i << " th child of " << front->data << " : ";
            cin >> child_data;

            tree_node<int> *child =new tree_node <int> (child_data);
            front->children.push_back(child);
            pending_nodes.push(child);
        }
        
    }
    
    return root;
}

void print_tree(tree_node<int> *root)
{
    queue<tree_node<int> *> piklu;
    piklu.push(root);
    while (piklu.size() != 0)
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

int count_nodes(tree_node<int> *root)
{
    
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += count_nodes(root->children[i]);
    }
    return ans;
}

int main()
{

    tree_node <int> *root = take_inp();
    print_tree(root);

    cout << "total number of nodes are : ";
    cout << count_nodes(root);

    return 0;
}