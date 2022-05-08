#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q;

public:
    void push(int data)
    {
        q.push(data);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
            return;

        q.pop();
    }

    int top()
    {
        if (q.empty())
            return -1;

        return q.front();
    }

    int size()
    {
        return q.size();
    }

    bool empty()
    {
        return size() == 0;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (!s.empty())
    {
        cout << s.top() << ", ";
        s.pop();
    }
}
