#include <vector>
class Solution {
    public:
        std::vector<std::vector<int>> generateMatrix(int n) {
            std::vector<std::vector<int>>  matrix(n, std::vector<int>(n, 0));
            int count = 1;
            int i = 0;
            int j = 0;
            int direction = 0;
            int total = n * n;
            while (count <= total) {
                if (direction == 0) {
                    //std::cout << "hello0\n";
                    if (j < n && matrix[i][j] == 0) {
               
                        matrix[i][j] = count;
                        count++;
                        j++;
                    } else {
                        direction++;
                        j--;
                        i++;
                    }
                } else if (direction == 1) {
                    // std::cout << "hello\n";
                    // std::cout << i;
                    // std::cout << j;
                    if (i < n && matrix[i][j] == 0) {
                        
                        matrix[i][j] = count;
                        count++;
                        i++;
                    } else {
                        direction++;
                        i--;
                        j--;
                    }
                } else if (direction == 2) {
                    if (j >= 0 && matrix[i][j] == 0) {
                       
                        matrix[i][j] = count;
                        count++;
                        j--;
                    } else {
                        direction++;
                        j++;
                        i--;
                    }
    
                }else if (direction == 3) {
                    if (i >= 0 && matrix[i][j] == 0) {
                       
                        matrix[i][j] = count;
                        count++;
                        i--;
                    } else {
                        direction = 0;
                        i++;
                        j++;
                    }
    
                }
            }
            return matrix;
        }
    };