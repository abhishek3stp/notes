#include <bits/stdc++.h>
using namespace std;

bool isValid(char s[])
{
    stack<char> stk;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        if (ch == '(')
            stk.push(ch);

        else if (ch == ')')
        {
            if (stk.empty())
                return false;
            stk.pop();
        }
    }

    return stk.empty();
}

int main()
{
    char s[] = "((a+b)+(c+d))";
    cout << isValid(s) << endl;
}
