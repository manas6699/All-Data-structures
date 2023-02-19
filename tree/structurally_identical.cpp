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

tree_node<int> *take_input()
{
    int root_data;
    // cout << "Enter root data & children data's manually : ";
    cin >> root_data;

    tree_node<int> *root = new tree_node<int>(root_data);
    queue<tree_node<int> *> pending_node;
    pending_node.push(root);

    while (pending_node.size() != 0)
    {
        tree_node<int> *front = pending_node.front();
        pending_node.pop();

        int num_child;
        // cout << "Enter the number of child of " << front->data << " : ";
        cin >> num_child;

        for (int i = 0; i < num_child; i++)
        {
            int child_data;

            // 10 3 20 30 40 2 40 50 0 0 0 0
            // cout << "Enter the " << i << " th data of " << front->data << " : ";
            cin >> child_data;

            tree_node<int> *child = new tree_node<int>(child_data);
            front->children.push_back(child);
            pending_node.push(child);
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

bool find_x(tree_node<int> *root, int x)
{

    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {

        return true;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        bool b = find_x(root->children.at(i), x);

        if (b)
        {
            return true;
        }
    }
    return false;
}

bool compare_tree(tree_node<int> *root1, tree_node<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    queue<tree_node<int>* > p1;
    p1.push(root1);

    queue<tree_node<int>* > p2;
    p2.push(root2);

    while (p1.size() != 0)
    {
        tree_node<int>* front1 = p1.front();
        p1.pop();

        tree_node<int>* front2 = p2.front();
        p2.pop();

        if (front1->children.size() == front2->children.size() && front1->data == front2->data)
        {
            for (int i = 0; i < front1->children.size(); i++)
            {
                p1.push(front1->children[i]);
                p2.push(front2->children[i]);
            }
        }
        else
        {
            return false;
        }
    }
    
    return true;
}

int main()
{

    cout << "Enter 1st root & children data manually : ";
    tree_node<int> *root1 = take_input();
    cout << "1st representation : " << endl;
    print_tree(root1);

    cout << "Enter 2nd root & children data manually : ";
    tree_node<int> *root2 = take_input();
    cout << "2nd representation : " << endl;
    print_tree(root2);

    // cout << "Your largest node of tree is : " << check_largest(root)->data;
    cout << "After comparing : ";

    // cout << root1->data << " " << root2->data << endl;

    if (compare_tree(root1, root2))
    {
        cout << "Matched !";
    }
    else
    {
        cout << "not matched !";
    }

    // 10 3 20 30 40 2 40 50 0 0 0 0

    return 0;
}
