#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue; 
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, combination, result);
            combination.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, target, 0, combination, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    
    vector<vector<int>> res = sol.combinationSum(candidates, target);
    for (const auto& v : res) {
        cout << "[ ";
        for (int num : v) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}
