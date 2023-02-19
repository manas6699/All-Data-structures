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
        for (int i = 0; i < word.size(); i++)
        {
            insertWord(root , word.substr(i));
        }
        
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
};

int main()
{
    tries t1;
   int t;
   cin >> t;
   while (t--)
   {
       string s1;
       cin >> s1;
       t1.insertWord(s1);
   }
   string user_ka_maa_ka_vosra;
   cin >> user_ka_maa_ka_vosra;
   if (t1.pattern_matching(user_ka_maa_ka_vosra))
   {
       cout << "Are nach gandu ! ache!!";
   }
   else
   {
       cout << "Dher leora ! naaaai baaal!!";
   }
   

    return 0;
}