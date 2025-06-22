#include <vector>
#include <unordered_map>
class Solution {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> group_lens;
        int groups = 0;
        std::vector<int> unions(edges.size() + 1, 0);
        for (std::vector<int>& i : edges) {
            if (unions[i[0]] == 0 && unions[i[1]] == 0) {
                groups++;
                unions[i[0]] = groups;
                unions[i[1]] = groups;
                group_lens[groups].push_back(i[0]);
                group_lens[groups].push_back(i[1]);
            }
            else if (unions[i[0]] != 0 && unions[i[1]] == 0) {
                unions[i[1]] = unions[i[0]];
                group_lens[unions[i[0]]].push_back(i[1]);
            }
            else if (unions[i[0]] == 0 && unions[i[1]] != 0) {
                unions[i[0]] = unions[i[1]];
                group_lens[unions[i[1]]].push_back(i[0]);
            }
            else if (unions[i[0]] == unions[i[1]]) {
                return i;
                // continue;
            }
            else {
                if (group_lens[unions[i[0]]].size() >= group_lens[unions[i[1]]].size()) {
                    int k = unions[i[1]];
                    for (int j : group_lens[unions[i[1]]]) {
                        unions[j] = unions[i[0]];
                        group_lens[unions[i[0]]].push_back(j);
                    }
                    group_lens.erase(k);
                   // groups--;

                } else {
                    int k = unions[i[0]];
                    for (int j : group_lens[unions[i[0]]]) {
                        unions[j] = unions[i[1]];
                        group_lens[unions[i[1]]].push_back(j);
                    }
                    group_lens.erase(k);
                   // groups--;
                }
            }
        }
        return {1,1};

    }
};