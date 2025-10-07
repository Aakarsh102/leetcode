#include <vector>
#include <unordered_map>
class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        int start = 0;
        int end = 0;

        std::unordered_map<int, int > map;
        int n = fruits.size();
        int count = 0;
        int m = 100000;
        int fruit = -1;
        while (end < n) {
            if (map.count(fruits[end]) == 0 && map.size() == 2) {
                for (const auto& i : map) {
                    if (i.second < m) {
                        m = i.second;
                        fruit = i.first;
                    }
                }
                map[fruits[end]] = end;
                map.erase(fruit);

                count = std::max(end - start, count);

                start = m + 1;
                m = 100000;
            } else {
                map[fruits[end]] = end;
            }
            end++;
        }
        count = std::max(end - start, count);
        return count;
    }
};