#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int mid;
        vector<int> result(2,-1);
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                result[0] = mid;
                result[1] = mid;
                while (result[0] > 0 && nums[result[0] - 1] == target)
                {
                    result[0]--;
                }
                while (result[1] < nums.size() - 1 && nums[result[1] + 1] == target)
                {
                    result[1]++;
                }
                break;
            }
        }
        return result;
    }
};