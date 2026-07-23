#include <cstdlib>
#include <cstdio>
#include <iostream>

int main() {
    int t, n, x;
    std::cin >> t;
    for (int j = 0; j < t; j++) {
        std::cin >> n >> x;
        // std::vector<int> vec(n, 0);
        int max_dist = 0;
        int a = 0;
        int b = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> b;
            max_dist = std::max(max_dist, b - a);
            std::swap(a, b);
        }

        max_dist = std::max(max_dist, 2 * (x - a));
        std::cout << max_dist << std::endl;
    }
    

    
}