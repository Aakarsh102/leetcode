#include <vector>

class Solution {
public:
    int minSwapsCouples(std::vector<int>& row) {
        int n = row.size();
        std::vector<int> index(n, -1);
        for (int i = 0; i < n; i++) {
            index[row[i]] = i;
        }
        int i = 0;
        int cur = 0;
        int couple = 0;
        int count = 0;
        while (i < n) {
            cur = row[i];
            couple = cur ^ 1;
            if (index[couple] == i + 1) {
                i++;
                i++;
                continue;
            }
            // if (couple > cur && index[couple] == i + 1) {
            //     i++;
            //     continue;
            // }
            // if (couple < cur && index[couple] == i - 1) {
            //     i++;
            //     continue;
            // }
            index[row[i + 1]] = index[couple];
            row[index[couple]] = row[i + 1]; 
            row[i + 1] = couple;
            index[couple] = i + 1;
            i += 2;
            count ++;
        }
        return count;
    }
};