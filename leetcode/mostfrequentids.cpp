class Solution {
public:
    std::vector<long long> mostFrequentIDs(std::vector<int>& nums, std::vector<int>& freq) {
        std::priority_queue<std::pair<long long, long long>> pq;
        std::unordered_map<long long, long long> um;
        std::pair<long long, long long> cur;
        std::vector<long long> res;
        for (int i = 0; i < freq.size(); i++) {
            um[nums[i]] += freq[i];
            cur = {um[nums[i]], nums[i]};
            pq.push(cur);
            while (!pq.empty()) {
                cur = pq.top();
                if (um[cur.second] != cur.first) {
                    pq.pop();
                } else {
                    break;
                }
            }
            res.push_back(cur.first);
        }
        return res;
    }
};