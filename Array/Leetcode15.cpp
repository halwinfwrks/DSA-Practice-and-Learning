#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int ptr1 = i + 1, ptr2 = nums.size() - 1;
            while (ptr1 < ptr2)
            {
                int sum = nums[i] + nums[ptr1] + nums[ptr2];
                if (sum < 0)
                {
                    ptr1++;
                }
                else if (sum > 0)
                {
                    ptr2--;
                }
                else
                {
                    result.push_back({nums[i], nums[ptr1], nums[ptr2]});
                    while (ptr1 < ptr2 && nums[ptr1] == nums[ptr1 + 1])
                        ptr1++;
                    while (ptr1 < ptr2 && nums[ptr2] == nums[ptr2 - 1])
                        ptr2--;
                    ptr1++;
                    ptr2--;
                }
            }
        }

        return result;
    }
};