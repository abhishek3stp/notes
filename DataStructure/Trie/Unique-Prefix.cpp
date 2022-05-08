#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool terminal;
    int freq;

    Node(char d)
    {
        data = d;
        terminal = false;
        freq = 0;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node('\0');
    }

    void insert(char *w)
    {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
                temp->freq++;
            }
            else
            {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
                temp->freq++;
            }
        }
        temp->terminal = true;
    }

    char *prefix(char *w)
    {
        char *ans = new char[10];
        Node *temp = root;

        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children[ch]->freq == 1)
            {
                ans[i] = ch;
                ans[i + 1] = '\0';
                return ans;
            }
            else
            {
                ans[i] = ch;
                temp = temp->children[ch];
            }
        }
        return w;
    }
};

int main()
{
    Trie t;
    char word[][10] = {"cobra", "dog", "dove", "duck", "cobras"};

    for (int i = 0; i < 5; i++)
        t.insert(word[i]);

    for (int i = 0; i < 5; i++)
        cout << t.prefix(word[i]) << endl;
}
