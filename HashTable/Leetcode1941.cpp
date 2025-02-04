#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        vector<int> count(26, 0);
        int target = count[0];
        for (char c : s)
            target = ++count[c - 'a'];

        for (int i = 0; i < 26; i++)
            if (count[i] != target && count[i] != 0)
                return false;

        return true;
    }
};