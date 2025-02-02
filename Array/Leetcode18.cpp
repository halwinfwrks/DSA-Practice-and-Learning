#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    /**
     * * Solution 1:
     * - Sort the array to make it easier to eliminate duplicates.
     * - Use two nested loops (i, j) to fix the first two elements.
     * - Use two-pointer approach (left, right) to find the remaining two elements.
     * - If the sum of four numbers is less than target, move left pointer to increase sum.
     * - If the sum is greater than target, move right pointer to decrease sum.
     * - If the sum matches the target, store the quadruplet and skip duplicate elements.
     * - Avoid duplicate quadruplets by checking adjacent elements.
     */
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n < 4)
            return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum < target)
                        left++;
                    else if (sum > target)
                        right--;
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
