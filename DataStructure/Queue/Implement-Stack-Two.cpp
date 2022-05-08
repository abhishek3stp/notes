#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    void push(int data)
    {
        q2.push(data);
        while (q1.size())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop()
    {
        if (q1.empty())
            return;

        q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return -1;

        return q1.front();
    }

    int size()
    {
        return q1.size();
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
