#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * *Solution 1: Using Binary Search
     * 1. Split the array into two halves using: mid = left + (right - left) / 2.
     * 2. If nums[mid] == target, return mid.
     * 3. Determine which half is increasing:
     *    3.1 If nums[left] < nums[mid], then the increasing part is [left, mid].
     *    3.2 Otherwise, the increasing part is [mid, right].
     * 4. Determine which part contains the target:
     *    4.1 If nums[left] < target < nums[mid], then the target is in [left, mid].
     *    4.2 Otherwise, the target is in [mid, right].
     * 5. Repeat steps 1-4 until left == right.
     * 6. Return -1 if left > right.
     */

    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};