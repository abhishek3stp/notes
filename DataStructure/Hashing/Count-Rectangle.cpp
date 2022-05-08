#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class Compare
{
public:
    bool operator()(Point p1, Point p2)
    {
        if (p1.x == p2.x)
            return p1.y < p2.y;

        return p1.x < p2.x;
    }
};

int countRectangle(vector<Point> &coords)
{
    set<Point, Compare> s;

    for (auto p : coords)
        s.insert(p);

    int ans = 0;
    for (auto it = s.begin(); it != prev(s.end()); it++)
    {
        for (auto jt = next(it); jt != s.end(); jt++)
        {
            Point p1 = *it;
            Point p2 = *jt;

            if (p1.x == p2.x or p1.y == p2.y)
                continue;

            Point p3(p2.x, p1.y);
            Point p4(p1.x, p2.y);

            if (s.find(p3) != s.end() and s.find(p4) != s.end())
                ans++;
        }
    }

    return ans / 2;
}

int main()
{
    vector<Point> coords;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            Point p(i, j);
            coords.push_back(p);
        }
    }

    cout << countRectangle(coords) << endl;
    return 0;
}
