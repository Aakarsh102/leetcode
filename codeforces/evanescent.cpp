#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t = 0;
    std::cin >> t;
    int n = 0;
    while (t > 0) {
        
        std::cin >> n;
        // std::cin.ignore();
        std::string s;
        std::cin >> s;
        // std::getline(std::cin, s);
        int left = 0;
        int right = 1;
        bool flag = true;
        int change = 0;
        std::vector<char> compressed;
        while (left < n) {
            while (right < n && s[left] == s[right]) {
                right++;
            }
            if (flag && left > 0 && left < n - 1 && s[left + 1] != s[left]) {
                if (s[left -  1] == s[left + 1]) {
                    // std::cout << t;
                    // std::cout << "here\n";
                    change = 2;
                    flag = false;
                } else {
                    change = 1;
                }
            }
            
            compressed.push_back(s[left]);
            left = right;
            right++;
        }
        std::cout << compressed.size() - change;
        t--;
        if (t != 0) {
            std::cout << "\n";
        }
    }
    return 0;
}