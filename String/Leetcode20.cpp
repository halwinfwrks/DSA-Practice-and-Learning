#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        const char open_br[] = {'{', '[', '('};
        const char close_br[] = {'}', ']', ')'};
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                st.push(s[i]);
                continue;
            }
            if (st.empty())
                return false;
            if (s[i] == '}' && st.top() != '{')
                return false;
            if (s[i] == ']' && st.top() != '[')
                return false;
            if (s[i] == ')' && st.top() != '(')
                return false;
            st.pop();
        }
        return st.empty();
    }
};