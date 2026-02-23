#include <iostream> 
#include <vector>

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
        std::vector<int> dp(n, 1);
        std::vector<std::vector<int> > store;
        for (int i = 0; i < n; ++i) {
            store.push_back({ vec[i] });
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (vec[j] < vec[i]) {
                    if (dp[j] + 1 >= dp[i]) {
                        if (dp[j] + 1 == dp[i]) {
                            store[j].push_back(vec[i]);
                            if (store[j] < store[i]) {
                                store[i] = store[j];
                            }
                            store[j].pop_back();
                        } else {
                            store[i] = store[j];
                            store[i].push_back(vec[i]);
                            dp[i] = dp[j] + 1;
                        }
                    }
                    
                }
            }
        }
        int m = 0;
        int ind;
        for (int i = 0; i < n; i++) {
            // m = std::max(m, dp[i]);
            if (store[i].size() == m){
                if (store[i] < store[ind]) {
                    ind = i;
                }
            }
            if (store[i].size() > m) {
                m = store[i].size();
                ind = i;
            }
        }
        std::cout << m << " ";
        // std::vector<int> ans;
        // while(ind != -1) {
        //     ans.push_back(vec[ind]);
        //     ind = max_sub[ind];
        // }
        // std::reverse(ans.begin(), ans.end());
        for (int i : store[ind]) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

    }
}