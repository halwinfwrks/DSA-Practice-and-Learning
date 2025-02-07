#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.length())
            return s;
        vector<vector<char>> map(numRows);
        int row = 0;
        int step = -1;
        for (int i = 0; i < s.length(); i++)
        {
            map[row].push_back(s[i]);
            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;
            row += step;
        }
        string result = "";
        for (int i = 0; i < map.size(); i++)
        {
            for (int j = 0; j < map[i].size(); j++)
            {
                result += map[i][j];
            }
        }
        return result;
    }
};