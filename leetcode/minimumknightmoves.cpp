#include <stdlib.h>
#include <queue>
#include <unordered_set>
class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = std::abs(x);
        y = std::abs(y);
        std::unordered_set<long long > s;
        std::queue<std::pair<int, int>> q;
        std::vector<std::pair<int, int>> dirs = {{1, 2}, {2, 1}, {-1, 2}, {1, -2}, {-2, 1}, {2, -1}, {-1, -2}, {-2, -1}};
        q.push({0,0});
        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                size --;
                std::pair<int, int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                if (i == x && j == y){return moves;}
                for (std::pair<int, int>& k : dirs) { 
                    int a = k.first + i;
                    int b = k.second + j;
                    if ((s.find(enc(a, b)) == s.end()) && a >= -2 && b >= -2 && a <= x + 2 && b <= y + 2) {
                        q.push({a, b});
                        s.insert(enc(a, b));
                    }
                }
            }
            moves++;
        }
        return -1;
    }
    inline long long enc(int x, int y) {
        return ((long long) x << 32 | y);
    }
};