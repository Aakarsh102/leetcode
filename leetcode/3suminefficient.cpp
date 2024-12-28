#include <vector>
#include <set>
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        
        std::set<std::vector<int>> three_sum;
        int sum;
        int i = 0;
        while (i < nums.size() - 2) {
            std::unordered_map<int, int> one;
            sum = -nums[i];
            int j = i + 1 ;
            while (j < nums.size()) {
                auto k = one.find(nums[j]);
                if (k != one.end()) {
                    std::vector<int> triplet = {-sum, k->second, k->first};
                    std::sort(triplet.begin(), triplet.end());
                    bool flag = false;
                    // for (vector<int> i : three_sum) {
                    //     if (i == triplet) {
                    //         flag = true;
                    //         break;
                    //     }
                    // }
                    // if (flag == false) {
                    //     three_sum.push_back(triplet);
                    // }
                    three_sum.insert(triplet);
                    
                }
                else {
                    one[sum - nums[j]] = nums[j];
                }
                j++;
            }
            i++;

        }
        std::vector ret(three_sum.begin(), three_sum.end());
        return ret;
    }
};