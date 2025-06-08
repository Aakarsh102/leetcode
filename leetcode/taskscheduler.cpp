#include <vector>
class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::vector<int> dict(26);
        int m = 0;
        for (char i : tasks) {
            dict[i - 'A']++;
            m = dict[i - 'A'] > m ? dict[i - 'A'] : m;
        }
        int count = 0;
        for (int i : dict) {
            if (i == m) {
                count++;
            }
        }
        int s = (n+1) * (m - 1) + count;
        if (s > tasks.size()) {
            return s;
        }
        return tasks.size();
        

    }
};