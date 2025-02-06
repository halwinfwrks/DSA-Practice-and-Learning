#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string result = "";
        if (strs.empty())
            return "";
        int start = 0;
        while (true)
        {
            result += strs[0][start];
            for (const auto &s : strs)
            {
                if (s.substr(0, start + 1) != result)
                    return result.substr(0, start);
            }
            start++;
        }
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            while (strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty())
                    return "";
            }
        }
        return prefix;
    }
};