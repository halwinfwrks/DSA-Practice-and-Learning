#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * * Solution:
     * 1. Initialize two pointers, 'left' and 'right', where 'right' starts at the last index,
     *    and 'left' is initially set to the index before 'right'.
     * 2. Traverse the array from right to left to find the first decreasing element (nums[left]).
     * 3. If such an element is found:
     *    - Find the smallest number greater than nums[left] on its right.
     *    - Swap nums[left] with that number.
     * 4. Reverse the elements after 'left' to get the next lexicographical permutation.
     * 5. If no decreasing element is found, reverse the entire array to get the smallest permutation.
     */
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int left, right;
        right = n - 1;
        left = right - 1;

        while (left >= 0 && nums[left] >= nums[left + 1])
            left--;
        if (left >= 0)
        {
            while (nums[right] <= nums[left])
                right--;
            swap(nums[left], nums[right]);
        }
        reverse(nums.begin() + left + 1, nums.end());
    }
};
