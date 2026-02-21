#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char c;
    map<char, TrieNode *> children;
    bool isEnd;
    int count;
    TrieNode(char c)
    {
        this->c = c;
        this->count = 0;
        this->isEnd = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        this->root = new TrieNode(' ');
    }

    void add(string word)
    {
        TrieNode *curr = this->root;
        for (char w : word)
        {
            if (curr->children[w] == NULL)
                curr->children[w] = new TrieNode(w);
            curr = curr->children[w];
            curr->count += 1;
        }
        curr->isEnd = true;
    }
    bool find(string word)
    {
        TrieNode *curr = this->root;
        for (char w : word)
        {
            if (!curr->children[w])
                return false;
            curr = curr->children[w];
        }
        return curr->isEnd;
    }
    int startWithCount(string word)
    {
        TrieNode *curr = this->root;
        for (char w : word)
        {
            if (!curr->children[w])
                return 0;
            curr = curr->children[w];
        }
        return curr->count;
    }
    void display()
    {
        cout << "Trie Structure:" << endl;
        printHelper(root, "", true);
    }
    void printHelper(TrieNode *node, string indent, bool isLast)
    {
        if (!node)
            return;

        // Print the branch line and the character
        cout << indent;
        if (isLast)
        {
            cout << "└── ";
            indent += "    ";
        }
        else
        {
            cout << "├── ";
            indent += "│   ";
        }

        // Highlight word endings with a '*' or similar symbol
        cout << node->c << (node->isEnd ? " (end)" : "") << "(" << node->count << ")" << endl;
        // cout << node->count;

        // Iterate through children
        auto it = node->children.begin();
        while (it != node->children.end())
        {
            char charKey = it->first;
            TrieNode *childNode = it->second;
            it++;
            bool lastChild = (it == node->children.end());
            printHelper(childNode, indent, lastChild);
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Trie *trie = new Trie();
    trie->add("apple");
    trie->add("applause");
    trie->add("apron");
    trie->add("food");
    trie->add("fool");
    trie->add("foolish");
    trie->display();
    cout << "app " << trie->startWithCount("app") << endl;
    cout << "ap " << trie->startWithCount("ap") << endl;
    cout << "land exists: " << trie->find("land") << endl;
    cout << "apron exists: " << trie->find("apron") << endl;
    cout << "odd exists: " << trie->find("odd") << endl;
}

// longest prefix

class TrieNode
{
public:
    char c;
    map<char, TrieNode *> children;
    bool isEnd;
    int count;
    TrieNode(char c)
    {
        this->c = c;
        this->count = 0;
        this->isEnd = false;
    }
};
void add(TrieNode *root, string word)
{
    TrieNode *curr = root;
    root->count++;
    for (char w : word)
    {
        if (curr->children[w] == NULL)
            curr->children[w] = new TrieNode(w);
        curr = curr->children[w];
        curr->count++;
    }
    curr->isEnd = true;
}
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int mn = 201;
        int n = strs.size();
        if (n == 1)
            return strs[0];
        TrieNode *root = new TrieNode(' ');
        TrieNode *curr = root;
        for (string word : strs)
        {
            if (word == "")
                return "";
            add(root, word);
        }
        string ans = "";
        bool flag = true;
        while (flag && curr->children.size() > 0)
        {
            for (auto [ch, node] : curr->children)
            {
                if (node->count == n)
                {
                    curr = node;
                    ans += curr->c;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        return ans;
    }
};
// word break
class TrieNode
{
public:
    char c;
    map<char, TrieNode *> children;
    bool isEnd;
    int count;
    TrieNode(char c)
    {
        this->c = c;
        this->count = 0;
        this->isEnd = false;
    }
};
void add(TrieNode *root, string word)
{
    TrieNode *curr = root;
    root->count++;
    for (char w : word)
    {
        if (curr->children[w] == NULL)
            curr->children[w] = new TrieNode(w);
        curr = curr->children[w];
        curr->count++;
    }
    curr->isEnd = true;
}
class Solution
{
public:
    map<int, bool> memo;
    bool helper(TrieNode *root, int idx, string word)
    {
        if (idx == word.size())
            return true;
        if (memo.find(idx) != memo.end())
            return memo[idx];
        TrieNode *curr = root;
        for (int i = idx; i < word.size(); i++)
        {
            if (curr->children[word[i]] == NULL)
            {
                memo[idx] = false;
                return false;
            }
            curr = curr->children[word[i]];
            if (curr->isEnd)
            {
                if (helper(root, i + 1, word))
                {
                    memo[idx] = true;
                    return true;
                }
            }
        }
        memo[idx] = false;
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        TrieNode *root = new TrieNode(' ');
        for (string word : wordDict)
            add(root, word);
        return helper(root, 0, s);
    }
};