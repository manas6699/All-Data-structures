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

    void suggestionsRec(trieNode *root, string currPrefix)
    {
        // found a string in Trie with the given prefix
        if (root->isTerminal)
        {
            cout << currPrefix;
            cout << endl;
        }

        // All children struct node pointers are NULL
        if (root->isTerminal)
        {
            return;
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->bantu[i])
            {
                // append current character to currPrefix string
                currPrefix.push_back(97 + i);

                // recur over the rest
                suggestionsRec(root->bantu[i], currPrefix);
                // remove last character
                currPrefix.pop_back();
            }
        }
    }

    // print suggestions for given query prefix.
    int printAutoSuggestions(trieNode *root, const string query)
    {
        trieNode *pCrawl = root;

        // Check if prefix is present and find the
        // the node (of last level) with last character
        // of given string.
        int level;
        int n = query.length();
        for (level = 0; level < n; level++)
        {
            int index = query[level] - 'a';

            // no string in the Trie has this prefix
            if (!pCrawl->bantu[index])
                return 0;

            pCrawl = pCrawl->bantu[index];
        }

        // If prefix is present as a word.
        bool isWord = (pCrawl->isTerminal);

        // If prefix is last node of tree (has no
        // children)
        bool isLast = pCrawl->isTerminal;

        // If prefix is present as a word, but
        // there is no subtree below the last
        // matching node.
        if (isWord && isLast)
        {
            cout << query << endl;
            return -1;
        }

        // If there are are nodes below last
        // matching character.
        if (!isLast)
        {
            string prefix = query;
            suggestionsRec(pCrawl, prefix);
            return 1;
        }
    }
    // for user
    int printAutoSuggestions(string word)
    {
        return printAutoSuggestions(root, word);
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

    // t1.auto_complete(t1, find_word);
    // cout << t1.find_node(find_word)->data;

  cout << t1.printAutoSuggestions(find_word);
    return 0;
}