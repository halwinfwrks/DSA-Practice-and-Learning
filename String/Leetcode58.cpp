#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.size() == 1)
            return (s[0] == ' ') ? 0 : 1;

        int count = 0;
        for(int i = s.size() - 1; i >=0 ; i--){
            if(s[i] == ' ' && count != 0) break;
            if(s[i] != ' ') count++;
        }
        return count;

    }
};
