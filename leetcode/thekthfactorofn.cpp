#include <vector>
#include <queue>
#include <cmath>
class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 0;
        int t = pow(n, 0.5);
        double nn = (double) n;
        std::priority_queue<int> l;
        double f;
        for (int i = 1; i <= t; i++) {
            f = nn/i;
            if (f == (int) f) {
                l.push(i);
                if (i != f) {
                    l.push(f);
                }
                
            }
        }

        t = l.size() - k;
        // std::cout << l.size() << std::endl;
        if (t < 0) {
            return -1;
        }
        for (int i = 0; i < t; i++) {
            l.pop();
        }
        return l.top();

    }
};