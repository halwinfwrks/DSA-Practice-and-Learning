#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> rows(n, -1);
        vector<int> cols(m, -1);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[j][i] == 0)
                {
                    rows[j] = 0;
                    cols[i] = 0;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (cols[i] == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (rows[i] == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};