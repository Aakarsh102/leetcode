#include <vector>
class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        int n = asteroids.size();
        std::vector<int> ret;
        int j = 0;
        int k = n;
        while (j < k) {
            n = asteroids.size();
            ret.clear();
            for (int i = 0; i < n; i++) {
                if (asteroids[i] > 0 && i < n - 1) {
                    if (asteroids[i + 1] < 0) {
                        if (asteroids[i] > -asteroids[i + 1]) {
                            ret.push_back(asteroids[i]);
                        } else if (asteroids[i] < -asteroids[i + 1]) {
                            ret.push_back(asteroids[i + 1]);
                        } 
                        i++;
                        continue;
                    }
                }
                ret.push_back(asteroids[i]);
            }
            j++;
            asteroids = ret;
        }
        return ret;
    }
};