#include <vector>
#include <unordered_set>
class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        std::unordered_set<int> s;
        int n = isConnected.size();
        if (n == 1) {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s.find(i) == s.end()) {
                fill_sets(isConnected, s, i);
                count++;
            }
        }
        return count;
    }
    void fill_sets(std::vector<std::vector<int>>& isConnected, std::unordered_set<int>& s, int index) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            if ((isConnected[index][i] == 1) && (s.find(i) == s.end())) {
                s.insert(i);
                fill_sets(isConnected, s, i);
            }
        }
    }
};