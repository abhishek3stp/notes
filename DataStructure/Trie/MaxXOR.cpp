#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int value)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (value >> i) & 1;
            if (bit == 0)
            {
                if (temp->left == NULL)
                    temp->left = new Node();
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                    temp->right = new Node();
                temp = temp->right;
            }
        }
    }

    int maxXorHelper(int value)
    {
        int currans = 0;
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (value >> i) & 1;
            if (bit == 0)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    currans += (1 << i);
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    currans += (1 << i);
                }
                else
                    temp = temp->right;
            }
        }
        return currans;
    }

    int maxXor(int input[], int n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            insert(input[i]);
            int currans = maxXorHelper(input[i]);
            cout << currans << " ";
            ans = max(ans, currans);
        }
        return ans;
    }
};

int main()
{
    int input[] = {3, 10, 5, 25, 2, 8};
    int n = sizeof(input) / sizeof(input[0]);
    Trie t;
    cout << t.maxXor(input, n) << endl;
}
