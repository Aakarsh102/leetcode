#include <vector>
#include <cmath>

class Solution {
public:
    int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        int l = 0;
        int r = 1000000001;
        int mid = 0;
        while (l < r) {
            mid = l + (r - l)/2;
            if (check_works(houses, heaters, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    bool check_works(std::vector<int>& houses, std::vector<int>& heaters, int r) {
        int i = 0;
        int j = 0;
        while (i < houses.size()) {
            if (abs(houses[i] - heaters[j]) > r) {
                if (j < heaters.size() - 1) {
                    j++;
                    continue;
                } else {
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};