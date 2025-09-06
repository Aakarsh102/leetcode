#include <vector>
#include <unordered_map>
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> map1;
        std::unordered_map<int, int> map2;
        for (int i : nums1) {
            map1[i]++;
        }
        for (int i : nums2) {
            map2[i]++ ;
        }
        std::vector<int> ret;
        for (const std::pair<int, int>& p : map1) {
            if (map2[p.first] > 0) {
                for (int i = 0; i < std::min(p.second, map2[p.first]); i++) {
                    ret.push_back(p.first);
                }
            }
        }
        return ret;
    }
};