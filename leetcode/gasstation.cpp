#include <vector>
class Solution {
    public:
        int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    
            int total = 0;
            int cur = 0;
            int start = 0;
            for (int i = 0; i < gas.size(); i++) {
                total += gas[i] - cost[i];
                cur += gas[i] - cost[i];
                if (cur < 0) {
                    start = i + 1;
                    cur = 0;
                }
            }
            return total < 0 ? -1 : start;
        }    
    };