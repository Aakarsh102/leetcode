#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
    std::string frequencySort(std::string s) {
        std::unordered_map<char, int> m;
        for (char i : s) {
            m[i]++;
        }
        std::vector<std::pair<int, char>> k;
        for (const auto& p : m) {
            k.push_back({-p.second, p.first});
        }
        std::sort(k.begin(), k.end());
        std::string fs = "";
        for (const auto& i : k) {
            for (int j = 0; j < -i.first; j++) {
                fs.push_back(i.second);
            }
        }
        // std::reverse(fs.begin(), fs.end());
        return fs;
    }
};