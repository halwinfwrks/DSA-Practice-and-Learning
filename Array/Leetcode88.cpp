#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Merge Sorted Array
 *
 * This function merges two sorted arrays into a single sorted array.
 *
 * @param nums1 The first sorted array with a length of m + n.
 * @param m The number of elements in nums1 that should be merged.
 * @param nums2 The second sorted array with a length of n.
 * @param n The number of elements in nums2.
 *
 * The function merges nums1 and nums2 into a single array sorted in non-decreasing order.
 * The final sorted array is stored inside the array nums1.
 */

class Solution
{
public:
    /**
     * * Solution 1:
     * 1. Initialize two pointers, one for each array, at the end of each array.
     * 2. Compare the elements at the current positions of both arrays. If the element in the first array is smaller , place it at the current position in the merged array and move the pointer in the first array on step by step.
     * 3. If the element in the second array is smaller, place it at the current position in the merged array and move the pointer in the second array on step by step.
     * 4. Repeat the comparison and placement process until one of the arrays is exhausted.
     * 5. Place the remaining elements from the non-exhausted array at the end of the merged array.
     * 6. Return the merged array.
     */
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
        return;
    }
};