#include <vector>
class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> dist(n, 400000000);
        std::vector<int> intermed(n, 400000000);
        dist[src] = 0;
        for (int j = 0; j < k + 1; j++) {
            intermed = dist;
            for (std::vector<int>& i : flights) {
                if (dist[i[0]] != 400000000 && intermed[i[1]] > (dist[i[0]] + i[2])) {
                    intermed[i[1]] = dist[i[0]] + i[2];
                }
            }
            dist = intermed;
            //swap(dist, intermed);
            // for (int l : dist) {
            //     std::cout << l << std::endl;
            // }
        }
        if (dist[dst] == 400000000) {
            return -1;
        }
        return dist[dst];
    }
};