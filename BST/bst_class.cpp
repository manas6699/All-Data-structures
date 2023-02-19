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
class bst
{
    binary_tree_node<int> *root;
    bool hasData(binary_tree_node<int> *root, int data)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        else if (data < root->data)
        {
            return hasData(root->left, data);
        }
        else
        {
            return hasData(root->right, data);
        }
    }
    binary_tree_node<int> *insertData(int data, binary_tree_node<int> *root)
    {
        if (root == NULL)
        {
            binary_tree_node<int> *newnode = new binary_tree_node<int>(data);
            return newnode;
        }
        if (data < root->data)
        {
            root->left = insertData(data, root->left);
        }
        else
        {
            root->right = insertData(data, root->right);
        }

        return root;
    }

    void printBst(binary_tree_node<int> *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " : ";
        if (root->right != NULL)
        {
            cout << "R" << root->right->data << " ";
        }
        if (root->left != NULL)
        {
            cout << "L" << root->left->data << " ";
        }
        cout << endl;
        printBst(root->right);
        printBst(root->left);
    }
    binary_tree_node<int> *deleteData(binary_tree_node<int> *root, int data)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (data > root->data)
        {
            root->right = deleteData(root->right, data);
            return root;
        }
        else if (data < root->data)
        {
            root->left = deleteData(root->left, data);
            return root;
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL)
            {
                binary_tree_node<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                binary_tree_node<int> *temp2 = root->left;
                root->left = NULL;
                delete root;
                return temp2;
            }
            else
            {
                binary_tree_node<int>* maxNode = root->left;
                while (maxNode->right != NULL)
                {
                    maxNode = maxNode->right;
                }
                int maxData = maxNode->data;
                root->data = maxData;
                root->left = deleteData(root->left , data);
                return root;
            }
        }
    }

public:
    bst()
    {
        root = NULL;
    }
    ~bst()
    {
        delete root;
    }
    void delete_data(int data)
    {
        root = deleteData(root , data);
    }
    void insert_data(int data)
    {
        this->root = insertData(data, this->root);
    }
    bool has_data(int data)
    {
        return hasData(root, data);
    }
    void print_bst()
    {
        return printBst(root);
    }
};

//      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

int main()
{
    cout << "Before deleting : " << endl;
    bst b;
    b.insert_data(10);
    b.insert_data(20);
    b.insert_data(30);
    b.insert_data(3);
    b.print_bst();
    cout << "After deleting : " << endl;
    b.delete_data(30);
    b.print_bst();

    return 0;
}
