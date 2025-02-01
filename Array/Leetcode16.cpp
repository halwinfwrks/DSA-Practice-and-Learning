#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        if (nums.size() < 3)
            return -1;
        if (nums.size() == 3)
            return nums[0] + nums[1] + nums[2];
        int result = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int ptr1 = i + 1;
            int ptr2 = nums.size() - 1;
            while (ptr1 < ptr2)
            {
                int sum = nums[i] + nums[ptr1] + nums[ptr2];
                if (sum == target)
                    return sum;
                else if (sum < target)
                    ptr1++;
                else
                    ptr2--;
                if (abs(sum - target) <= abs(result - target))
                    result = sum;
            }
        }
        return result;
    }
};