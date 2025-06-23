#include <vector>
class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int direction = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<bool>> dp(m, std::vector<bool>(n, false));
        std::vector<int> thing;
        int i = 0;
        int j = 0;
        int count = 0;
        int prod = m * n;
        while (count < prod) {
            if (direction == 0) {
                if (dp[i][j] == false) {
                    thing.push_back(matrix[i][j]);
                    count++;
                    dp[i][j] = true;
                }
                if (j >= n - 1 || dp[i][j + 1] == true) {
                    direction = direction + 1 == 4 ? 0 : direction + 1;
                    continue;
                }
                j++;
            }
            else if (direction == 1) {
                if (dp[i][j] == false) {
                    thing.push_back(matrix[i][j]);
                    count++;
                    dp[i][j] = true;
                }
 
                if (i >= m - 1 || dp[i + 1][j] == true) {
                    direction = direction + 1 == 4 ? 0 : direction + 1;
                    continue;
                }
                i++;
            }
            else if (direction == 2) {
                if (dp[i][j] == false) {
                    thing.push_back(matrix[i][j]);
                    count++;
                    dp[i][j] = true;
                }
                if (j <= 0 || dp[i][j - 1] == true) {
                    direction = direction + 1 == 4 ? 0 : direction + 1;
                    continue;
                }
                j--;
            }
            else {
                if (dp[i][j] == false) {
                    thing.push_back(matrix[i][j]);
                    count++;
                    dp[i][j] = true;
                }
                if (i <= 0 || dp[i - 1][j] == true) {
                    direction = direction + 1 == 4 ? 0 : direction + 1;
                    continue;
                }
                i--;
            }
        }
        return thing;
    }
};