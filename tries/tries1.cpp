#include <bits/stdc++.h>
using namespace std;

class trieNode
{
public:
    char data;
    trieNode **bantu;
    bool isTerminal;

    trieNode(char data)
    {
        this->data = data;
        bantu = new trieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            bantu[i] = NULL;
        }

        isTerminal = false;
    }
};

class tries
{
    trieNode *root;

public:
    tries()
    {
        root = new trieNode('\0');
    }

    void insertWord(trieNode *root, string word)
    {

        // base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // small calculation
        int index = word[0] - 'a';
        trieNode *child;
        if (root->bantu[index] != NULL)
        {
            child = root->bantu[index];
        }
        else
        {
            child = new trieNode(word[0]);
            root->bantu[index] = child;
        }

        // recursive call
        insertWord(child, word.substr(1));
    }
    // for user
    void insertWord(string word)
    {
        insertWord(root, word);
    }

    void search(string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // small calculation
        int index = word[0] - 'a';

        if (root->bantu[index] != NULL)
        {
            cout << word[0] << " matched!" << endl;
            // return true;
        }
        else
        {
            root->isTerminal = false;

            // return false;
            cout << word[0] << " not matched!" << endl;
        }

        // recursive call
        search(word.substr(1));
    }
    bool searchTries(trieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            return root->isTerminal;
        }
        // small calculation
        trieNode *child;
        int index = word[0] - 'a';

        if (root->bantu[index] != NULL)
        {
            child = root->bantu[index];
        }
        else
        {
            return false;
        }

        // recursive call
        return searchTries(child, word.substr(1));
    }

    // for user
    bool searchTries(string word)
    {
        return searchTries(root, word);
    }

    void removeTrie(trieNode *root ,string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        // small calculation
        trieNode *child;
        int index = word[0] - 'a';

        if (root->bantu[index] != NULL)
        {
            child = root->bantu[index];
        }
        else
        {
            return;
        }
        // recursion call
        return removeTrie(child, word.substr(1));
        
        // remove the child node if it is useless
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->bantu[i] != NULL)
                {
                    return;
                }
                delete child;
                root->bantu[index] = NULL;
            }
            
        }
        
    }
    // for user
    void removeTrie(string word)
    {
        removeTrie(root , word);
    }
};

int main()
{
    tries t1;
    t1.insertWord("man");
    t1.insertWord("mine");
    t1.insertWord("mind");

    //t1.search("anm");

    if (t1.searchTries("mine"))
    {
        cout << "The word is present!";
    }
    else
    {
        cout << "The word is absent!";
    }
    cout << endl << " After deleting : " ;
    t1.removeTrie("mine");
    if (t1.searchTries("mind"))
    {
        cout << "The word is present!";
    }
    else
    {
        cout << "The word is absent!";
    }

    return 0;
}