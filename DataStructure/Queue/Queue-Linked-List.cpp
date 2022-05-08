#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int csize;
    list<int> l;

public:
    Queue()
    {
        csize = 0;
    }

    bool empty()
    {
        return csize == 0;
    }

    void push(int data)
    {
        l.push_back(data);
        csize++;
    }

    void pop()
    {
        if (!empty())
        {
            l.pop_front();
            csize--;
        }
    }

    int front()
    {
        return l.front();
    }
};

int main()
{
    Queue q;

    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty())
    {
        cout << q.front() << ", ";
        q.pop();
    }
}
