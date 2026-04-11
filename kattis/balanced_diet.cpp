#include <iostream>
#include <vector>
#include <math.h>

// Used the subset sum dp approach
// inspired by https://www.geeksforgeeks.org/partition-problem-dp-18/

int main() {
    int n;
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }
        std::vector<int> vec;
        int a;
        for (int i = 0; i < n; i++) {
            std::cin >> a;
            vec.push_back(a);
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += vec[i];
        }
        int k = sum;
        sum = sum/2;
        std::vector<int> dp(sum + 1, false);
        dp[0] = 1;
        for (int i : vec) {
            if (i > sum) {
                continue;
            }
            for (int j = sum; j >= i; j--) {
                if (dp[j - i]) {
                    dp[j] = true;
                }
            }
        }
        a = 0;
        for (int i = sum; i >= 0; i--) {
            if (dp[i]) {
                a = i;
                break;
            }  
        }
        int b = abs(k - a);
        if (a > b) {
            std::cout << a << " " << b << std::endl;
        } else {
            std::cout << b << " " << a << std::endl;
        }
    }
}