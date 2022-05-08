#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int f, r;
    int csize, msize;

public:
    Queue(int dsize = 5)
    {
        arr = new int[dsize];
        csize = 0;
        msize = dsize;
        f = 0;
        r = msize - 1;
    }

    bool full()
    {
        return csize == msize;
    }

    bool empty()
    {
        return csize == 0;
    }

    void push(int data)
    {
        if (!full())
        {
            r = (r + 1) % msize;
            arr[r] = data;
            csize++;
        }
    }

    void pop()
    {
        if (!empty())
        {
            f = (f + 1) % msize;
            csize--;
        }
    }

    int front()
    {
        return arr[f];
    }

    ~Queue()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main()
{
    Queue q(3);

    q.push(0);
    q.push(1);
    q.push(2);
    q.pop();
    q.push(3);

    while (!q.empty())
    {
        cout << q.front() << ", ";
        q.pop();
    }
}
