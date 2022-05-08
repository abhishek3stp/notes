#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool terminal;

    Node(char d)
    {
        data = d;
        terminal = false;
    }
};

class Trie
{
    Node *root;
    int cnt;

public:
    Trie()
    {
        root = new Node('\0');
        cnt = 0;
    }

    void insert(char *w)
    {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children.count(ch))
                temp = temp->children[ch];
            else
            {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        cnt++;
        temp->terminal = true;
    }

    bool find(char *w)
    {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];

            if (temp->children.count(ch) == 0)
                return false;
            else
                temp = temp->children[ch];
        }
        return temp->terminal;
    }
};

int main()
{
    Trie t;
    char word[][10] = {"a", "not", "apple", "news", "hello"};

    for (int i = 0; i < 5; i++)
        t.insert(word[i]);

    char *w1 = "apple";
    char *w2 = "no";

    cout << t.find(w1) << endl;
    cout << t.find(w2) << endl;
}
