
#include <functional> // for std::hash
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int kSimilarity(std::string s1, std::string s2) {
        std::queue<std::pair<std::string, int>> q;
        std::unordered_set<std::string> s;
        q.push({s1, 0});
        s.insert(s1);
        int i =0;
        int min_count = 20000000;
        while(!q.empty()) {
            std::string cur = q.front().first;
            int depth = q.front().second;
            if (cur == s2) {
                return depth;
            }
            q.pop();
            int ps = 0;
            // std::cout << i << std::endl;
            // i++;
            while (ps < s1.size()) {
                if (cur[ps] != s2[ps]) {
                    for (int i = ps + 1; i < s1.size(); i++) {
                        if (cur[i] == s2[ps] && cur[i] != s2[i]) {
                            std::swap(cur[ps], cur[i]);
                            if (s.find(cur) != s.end()) {
                                std::swap(cur[ps], cur[i]);
                                continue;
                            }
                            q.push({cur, depth + 1});
                            s.insert(cur);
                            std::swap(cur[ps], cur[i]);
                        }
                    }
                    break;
                } 
                ps++;
                
            }

        }
        return min_count;
        
    }
    
};

