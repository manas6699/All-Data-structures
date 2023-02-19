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

    void removeTrie(trieNode *root, string word)
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
        removeTrie(root, word);
    }
    bool pattern_matching(trieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            return true;
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
        return pattern_matching(child, word.substr(1));
    }
    bool pattern_matching(string word)
    {
        return pattern_matching(root, word);
    }
    
    void auto_complete(trieNode *root, tries t1, string word)
    {
        if (!t1.pattern_matching(word))
        {
            return;
        }
        if (word.size() == 0)
        {
            return;
        }
        trieNode *child;
        int index = word[0] - 'a';

        if (root->bantu[index] != NULL)
        {
            child = root->bantu[index];
            cout << word + child->data  << endl;
        }
        else
        {
            return;
        }
        // recursive call
        return auto_complete(child, t1, word.substr(1));
    }
    // for user
    void auto_complete(tries t1, string word)
    {
        return auto_complete(root, t1, word);
    }
};

int main()
{
    tries t1;
    int t;
    cin >> t;
    string s1[t];
    for (int i = 0; i < t; i++)
    {
        cin >> s1[i];
        t1.insertWord(s1[i]);
    }
    string find_word;
    cin >> find_word;

    t1.auto_complete(t1, find_word);
    return 0;
}