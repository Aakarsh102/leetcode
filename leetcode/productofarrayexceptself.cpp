#include <vector>
class Solution {
    public:
        std::vector<int> productExceptSelf(std::vector<int>& nums) {
            int n = nums.size();
            std::vector<int> pre_pro;
            std::vector<int> suf_pro(n, 0);
            pre_pro.push_back(nums[0]);
            suf_pro[n - 1] = nums[n - 1];
            for (int i = 1; i < n; i++) {
                pre_pro.push_back(pre_pro.back() * nums[i]);
                suf_pro[n - i - 1] = suf_pro[n - i] * nums[n - i - 1];
            }
            std::vector<int> ret;
            for (int i = 0; i < n; i++) {
                if (i != 0 && i != n - 1) {
                    ret.push_back(pre_pro[i - 1] * suf_pro[i + 1]);
                }
                else if (i == 0) {
                    ret.push_back(suf_pro[1]);
                }
                else if (i == n - 1) {
                    ret.push_back(pre_pro[n - 2]);
                }
                
            }
            return ret;
        }
    };