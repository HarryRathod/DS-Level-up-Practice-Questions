#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return true;
    return false;
}

bool redundantParanthesis(string s)
{
    stack<char> st;
    for(auto ch:s)
    {
        if(ch!=')')
            st.push(ch);
        else{
            bool operator_found=false;
            while(!st.empty() && st.top()!='(')
            {
                if(isOperator(st.top()))
                    operator_found=true;
                st.pop();
            }
            st.pop();
            if(operator_found==false)
                return true;
        }
    }
    return false;
}

int main()
{
    string s = "(2*(2+4))";
    string s2="(5*(4))";

    cout <<redundantParanthesis(s)<<endl;
    cout <<redundantParanthesis(s2)<<endl;

    return 0;
}