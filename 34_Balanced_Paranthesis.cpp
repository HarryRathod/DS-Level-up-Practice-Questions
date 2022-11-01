#include <bits/stdc++.h>
using namespace std;

bool balancedParanthesis(string s)
{
    stack<char> st;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (st.empty())
                return false;
            else if (s[i] == ')' && st.top() == '(')
                st.pop();
            else if (s[i] == '}' && st.top() == '{')
                st.pop();
            else if (s[i] == ']' && st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    return false;
}

bool balancedParanthesis2(string s)
{
    stack<char> st;
    for (auto ch : s)
    {
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
            st.push(ch);
            break;
        case ')':
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
            break;

        case '}':
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
            break;

        case ']':
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
            break;
        default:
            continue;
        }
    }
    if(st.empty())
        return true;
    return false;
}

int main()
{
    string s = "(2*{2+4[4](3)})";

    cout << balancedParanthesis(s) << endl;
    cout << balancedParanthesis2(s) << endl;

    return 0;
}