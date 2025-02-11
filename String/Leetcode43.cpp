#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.size(), len2 = num2.size();
        vector<int> result(len1 + len2, 0);
        for (int j = len2 - 1; j >= 0; j--)
        {
            for (int i = len1 - 1; i >= 0; i--)
            {
                int num = (num1.at(i) - '0') * (num2.at(j) - '0') + result[i + j + 1];
                result[i + j + 1] = num % 10;
                result[i + j] += num / 10;
            }
        }
        string res = "";
        bool start = false;
        for (int i = 0; i < result.size(); i++)
        {
            if (result[i] != 0)
                start = true;
            if (start)
                res += to_string(result[i]);
        }
        return res == "" ? "0" : res;
    }
};