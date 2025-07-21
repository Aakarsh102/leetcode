#include <vector> 
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int target = temperatures[0];
        int index;
        std::vector<int> ret(temperatures.size(), 0);
        int i = 0;
        int j;
        std::vector<int> stack;
        while (i < temperatures.size()) {
            
            while (!stack.empty() && temperatures[i] > temperatures[stack.back()]){
                
                j = stack.back();
                ret[j] = i - j;
                stack.pop_back();
            }
            stack.push_back(i);
            i++;
        }
            
        return ret;
    }
};