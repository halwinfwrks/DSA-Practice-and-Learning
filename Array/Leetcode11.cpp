#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * * Solution 1: O(n^2) -> it is not efficient.
     * 1. check condition if array input has less than 2 elements, return false
     * 2. init a variable to store the result
     * 3. loop through the array, for each element, loop through the rest of the array and calc the area of the rectangle
     * 4. if the area is greater than the result, update the result
     * 5. return the result
     */
    int maxArea(vector<int> &height)
    {
        if (height.size() < 2)
        {
            return -1;
        }

        int result = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int area = min(height[i], height[j]) * (j - i);
                result = max(result, area);
            }
        }
        return result;
    }

    /**
     * *Solution 2: use 2 pointer, one from the start, one from the end, move the one that has smaller height
     */
    int maxArea(vector<int> &height)
    {
        if (height.size() < 2)
        {
            return -1;
        }
        int result = 0;
        int ptr1 = 0, ptr2 = height.size() - 1;
        while (ptr2 > ptr1)
        {
            result = max(result, min(height[ptr1], height[ptr2]) * (ptr2 - ptr1));
            if (height[ptr1] < height[ptr2])
                ptr1++;
            else
                ptr2--;
        }
    }
};