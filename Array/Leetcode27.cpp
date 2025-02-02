#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    /**
     * * Solution:
     * 1. Initialize a pointer 'left' to track the position of valid elements.
     * 2. Iterate through the array with a pointer 'right'.
     * 3. If nums[right] is not equal to 'val', copy nums[right] to nums[left] and increment left.
     * 4. Continue until all elements are checked.
     * 5. Return 'left' as the new length of the array after removal.
     */
    int removeElement(vector<int> &nums, int val)
    {
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] != val)
            {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};
