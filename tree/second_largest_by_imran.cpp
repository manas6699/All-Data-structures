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

class my_pair
{
public:
    int largest;
    int second_largest;

    my_pair()
    {
        largest = INT_MIN;
        second_largest = 0;
    }
};

tree_node<int> *take_input()
{
    int root_data;
    cout << "Enter root & corrosponding childrens : ";
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

my_pair second_largest(tree_node<int> *root)
{
    my_pair ans;

    if (root->data > ans.largest)
    {
        ans.largest = root->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        my_pair temp = second_largest(root->children.at(i));

        if (temp.largest < ans.largest)
        {
            if (temp.largest > ans.second_largest)
            {
                ans.second_largest = temp.second_largest;
            }
        }
        else
        {
            if (ans.largest > temp.second_largest)
            {
                ans.second_largest = ans.largest;
            }
            else
            {
                ans.second_largest = temp.second_largest;
            }
            
            ans.largest = temp.largest;
        }
    }

    return ans;
}

int main()
{

    tree_node<int> *root = take_input();
    print_tree(root);
    cout << "Second largest element is : " << second_largest(root).second_largest << endl;
    cout << "Largest element is : " << second_largest(root).largest;

    //      10 3 20 30 40 2 40 50 0 0 0 0
    //      10 3 20 30 40 0 2 50 60 3 70 80 90 0 0 0 0 0
    return 0;
}
