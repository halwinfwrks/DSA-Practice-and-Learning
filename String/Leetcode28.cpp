#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if(needle.size() > haystack.size()) return -1;
        int length = needle.size();

        for (int i = 0; i <= haystack.size() - length; i++)
        {
            if (haystack.substr(i, length) == needle)
                return i;
        }
        return -1;
    }
};
