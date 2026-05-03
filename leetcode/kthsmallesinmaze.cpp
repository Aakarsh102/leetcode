#include <vector>
#include <queue>
class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        std::priority_queue<int> pq;
        int n = matrix.size();
        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (pq.size() < k) {
                    pq.push(matrix[i][j]);
                } else if (pq.top() > matrix[i][j]) {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }
};