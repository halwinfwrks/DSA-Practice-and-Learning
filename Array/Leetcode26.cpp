#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

/**
 * Removes duplicates from a sorted array in-place and returns the count of unique elements.
 *
 * Given a sorted array of integers, modify it such that each unique element appears only once,
 * maintaining their original order. The function returns the count of unique elements.
 *
 * The array is modified in-place, with the first 'k' elements containing the unique elements,
 * where 'k' is the count of unique elements. The remaining elements are not significant.
 *
 * @param nums A sorted array of integers.
 * @return The count of unique elements in the array.
 */

class Solution
{
public:
    /**
     * * Solution 1:
     * 1. Initialize a counter to track the position of the last unique element.
     * 2. Iterate through the array, comparing each element with the next one.
     * 3. If the elements are equal, remove the duplicate element.
     * 4. If the elements are different, increment the counter.
     * 5. Repeat steps 2-4 until the end of the array is reached.
     * 6. Return the count of unique elements.
     */
    int removeDuplicates(vector<int> &nums)
    {
        int count = 0;
        while (true)
        {
            if (count >= nums.size() - 1)
                break;
            if (nums[count] == nums[count + 1])
                nums.erase(nums.begin() + count + 1);
            else
                count++;
        }
        return nums.size();
    }
    /**
     * * Solution 2:
     * 1. Initialize two pointers, 'i' and 'j', to the start of the array.
     * 2. Iterate through the array, comparing each element with the next one.
     * 3. If the elements are equal, increment 'j' to skip the duplicate element.
     * 4. If the elements are different, copy the unique element to the position pointed by 'i' and increment
     * 5. Repeat steps 2-4 until the end of the array is reached.
     * 6. Return the count of unique elements.
     */
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int i = 0;

        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
                i++;
            nums[i] = nums[j];
        }
        return i + 1;
    }
};