#include <bits/stdc++.h>
using namespace std;

bool canPaint(int length[], int borad, int painter, int min_time)
{
    int painterUsed = 1;
    int currTime = 0;
    for (int i = 0; i < borad; i++)
    {
        if (currTime + length[i] > min_time) // previous painter not paint this borad
        {
            painterUsed++;
            currTime = length[i];
            if (painterUsed > painter)
                return false;
        }
        else
            currTime += length[i];
    }
    return true;
}

int main()
{
    int painter, board, sum = 0;
    cin >> painter >> board;
    int length[board];
    for (int i = 0; i < board; i++)
        cin >> length[i];

    for (int i = 0; i < board; i++) // time taken by single painter
        sum += length[i];

    int s = *max_element(length, length + board), e = sum;
    int ans = INT_MAX;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (canPaint(length, board, painter, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    cout << ans;
}
