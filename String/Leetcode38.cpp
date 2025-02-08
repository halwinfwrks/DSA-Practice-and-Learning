#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string result = "1";
        string tmp = "";
        int slow = 0, fast = 0;
        for (int i = 1; i < n; i++)
        {
            while (fast < result.size())
            {
                if (result[fast] == result[slow])
                    fast++;
                else
                {
                    tmp += to_string(fast - slow) + result[slow];
                    slow = fast;
                }
            }
            tmp += to_string(fast - slow) + result[slow];
            result = tmp;
            tmp = "";
            slow = fast = 0;
        }
        return result;
    }
};