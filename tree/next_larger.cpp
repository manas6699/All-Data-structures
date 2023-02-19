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
    cout << "Enter root data : ";
    cin >> root_data;

    tree_node<int> *root = new tree_node<int>(root_data);
    queue<tree_node<int> *> pending_node;
    pending_node.push(root);

    while (pending_node.size() != 0)
    {
        tree_node<int> *front = pending_node.front();
        pending_node.pop();

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

tree_node<int> *check_largest(tree_node<int> *root)
{
    int sum = INT_MIN;

    tree_node<int> *max_node = NULL;
    queue<tree_node<int> *> piklu;
    piklu.push(root);
    while (piklu.size() != 0)
    {
        int curr_sum = 0;
        tree_node<int> *front_node = piklu.front();
        piklu.pop();
        curr_sum += front_node->data;
        // cout << front_node->data << " : ";

        for (int i = 0; i < front_node->children.size(); i++)
        {
            curr_sum += front_node->children[i]->data;
            piklu.push(front_node->children[i]);
        }

        if (curr_sum > sum)
        {
            sum = curr_sum;
            max_node = front_node;
        }

        // cout << endl;
    }
    return max_node;
}

int next_largest(tree_node<int> *root, int n)
{
    int k;
    queue<tree_node<int> *> p1;
    p1.push(root);

    while (p1.size() != 0)
    {
        tree_node<int> *vivid = p1.front();
        p1.pop();

        if (vivid->data < n || vivid->data == n)
        {
            for (int i = 0; i < vivid->children.size(); i++)
            {
                p1.push(vivid->children[i]);
            }
        }
        else
        {
            k = vivid->data;
            break;
        }
    }
    return k;
}

int main()
{

    tree_node<int> *root = take_input();
    print_tree(root);

    int n;
    cout << "Enter next largest find value : ";
    cin >> n;

    cout << "Next largest is : " << next_largest(root , n);

    //      10 3 20 30 40 2 40 50 0 0 0 0
    return 0;
}
