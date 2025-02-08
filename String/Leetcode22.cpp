#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void backtrack(vector<string> &result, string current, int open, int close, int n) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (open < n) 
            backtrack(result, current + "(", open + 1, close, n);
        if (close < open) 
            backtrack(result, current + ")", open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for (auto p : s.generateParenthesis(4))
        cout << p << endl;
    return 0;
}
