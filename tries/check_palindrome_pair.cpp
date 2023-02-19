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
};

string convert_palindrome(string s1)
{
    string s2;

    for (int i = s1.size(); i >= 0; i--)
    {
        // cout << s1[i] << " " ;
        s2.push_back(s1[i]);
    }
    return s2;
}


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
    bool flag = 0;
    
    for (int i = 0; i < t; i++)
    {
      reverse(s1[i].begin(), s1[i].end());
     // convert_palindrome(s1[i]);
      
      if (t1.searchTries(s1[i]))
      {
        cout << "exists" << endl;
        flag = 1;
        break;
      }
    }
    
    if (!flag)
    {
      cout << "doesn't" << endl;
    }

    
    return 0;
}