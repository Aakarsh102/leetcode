#include <vector>
#include <string>
#include <unordered_map>
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> ret;
        std::unordered_map<std::string, std::vector<std::string>> hashmap;
        std::string store;
        for (int i = 0; i < strs.size(); i ++) {
            store = strs[i];
            std::sort(strs[i].begin(), strs[i].end());
            hashmap[strs[i]].push_back(store);
        }
        for (const std::pair<std::string, std::vector<std::string>>& i : hashmap) {
            ret.push_back(i.second);
        }
        return ret;
    }
};