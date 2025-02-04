#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        map<char, vector<string>> digit_mapping = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}};

        vector<string> result;
        if (digits.empty())
            return result;

        result.push_back("");
        for (char digit : digits)
        {
            if (digit_mapping.find(digit) != digit_mapping.end())
            {
                vector<string> temp;
                for (const auto &letter : digit_mapping[digit])
                {
                    for (int i = 0; i < result.size(); i++)
                    {
                        temp.push_back(result[i] + letter);
                    }
                }
                result = temp;
            }
        }
        return result;
    }
};