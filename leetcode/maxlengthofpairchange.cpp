#include <vector>
#include <algorithm>
class Solution {
public:
    bool c(std::vector<int> a, std::vector<int> b) {
        return a[1] < b[1];
    }
    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        int n = pairs.size();
        if (n == 1) {
            return 1;
        }
        // auto k = [](std::vector<int> a, std::vector<int> b) {
        //     return a[1] < b[1];
        // };
        
        std::sort(pairs.begin(), pairs.end(), [](std::vector<int>& a, std::vector<int>& b) {
        return a[1] < b[1];
    });
        int count = 0;
        int start = -1001;
        for (const std::vector<int>& i : pairs) {
            if (i[0] > start) {
                count += 1;
                start = i[1];
            }
        }
        return count;
    }
};