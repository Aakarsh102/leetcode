#include<vector>
class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int count = 0;
        int n = citations.size();
        int i = 1;
        while (i <= n) {
            if ( i <= citations[n - i]) {
                count++;
            }
            i++;
        }
        return count;
    }
};