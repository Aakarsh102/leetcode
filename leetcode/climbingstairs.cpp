class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> store;
        store.push_back(1);
        store.push_back(2);
        int i = 2;
        while (i < n) {
            // if (i % 2 == 1) {
            //     store.push_back(store[i - 1] + 1);
            // } else {
            //     store.push_back(store[i - 1] + 1);
            // }
            store.push_back(store[i - 1] + store[i - 2]);
            i++;
        }
        return store[n - 1];
    }
};