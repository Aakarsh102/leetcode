#include <vector>
#include <unordered_set>
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        std::unordered_set<int> s;
        for (const int& i : nums) {
            s.insert(i);
        }
        int longest_yet = 1;
        int cur_length = 0;
        for (const int& i : s) {
            if (s.find(i - 1) == s.end()) { // Bro remember these things 
            // you put the - 1 to avoid any overflow.
                cur_length = 1;
                int cur = i + 1;
                while (s.find(cur) != s.end()) {
                    s.erase(cur);
                    cur_length++;
                    cur++;
                    
                }
                longest_yet = std::max(cur_length, longest_yet);
            }
        }
        return longest_yet;
        
    }
};