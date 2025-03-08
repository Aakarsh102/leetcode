class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> ret_vec;
        for (int& i : nums) {
            const auto ret = std::lower_bound(ret_vec.begin(), ret_vec.end(), i);
            if (ret == ret_vec.end()) {
                ret_vec.push_back(i);
            } else {
                *ret = i;
            }
        }
        return ret_vec.size();
    }
};