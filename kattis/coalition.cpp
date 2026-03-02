#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip>
int main() {
    int n;
    std::cin >> n;
    // s
    for (int i = 0; i < n; i++) {
        int parties = 0;
        std::cin >> parties;
        // std::cout << parties;
        int s;
        int p;
        std::vector<std::pair<int, int> > vec;
        for (int j = 0; j < parties; j++) {
            std::cin >> s;
            std::cin >> p;
            // std::cin.ignore();
            vec.push_back({s, p});
        }
        std::vector<double> dp(151, 0);
        dp[0] = 1.0;
        for (int j = 0; j < parties; j++) {
            for (int k = 150; k > 0; k--) {
                if (k >= vec[j].first) {
                    dp[k] = std::max(dp[k], (dp[k - vec[j].first] * (double)(vec[j].second))/100);
                } else {
                    break;
                }
            }
        }
        double ma = 0;
        for (int j = 76; j <= 150; j++) {   
            ma = std::max(ma, (dp[j]));
        }
        std::cout << std::fixed << std::setprecision(6) << ma * 100 << "\n";
        //std::cout << ma * 100 << std::endl;
    }
}