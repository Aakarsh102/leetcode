#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <unordered_set>



int do_backtrack(std::vector<std::vector<int>>& teams, bool hates[16][16], int index, int total_teams, int best, int n) {
    if (index == n + 1) {
        return total_teams;
    }
    if (total_teams >= best) {
        return 10000000;
    }
    bool found = true;
    for (int i = index; i <= index; i++) {
        for (int j = 0; j < teams.size(); j++) {
            found = true;
            for (int k : teams[j]) {
                if (hates[index][k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                teams[j].push_back(i);
                int l = do_backtrack(teams, hates, index + 1, total_teams, best, n);
                best = std::min(best, l);
                teams[j].pop_back();
            }
        }
        
        teams.push_back({i});
        int l = do_backtrack(teams, hates, index + 1, total_teams + 1, best, n);
        best = std::min(best, l);
        teams.pop_back();
        
        found = true;
    }
    return best;
}

int main() {
    int n, m;
    while (std::cin >> n) {
        std::cin >> m; 
        if (n == 0 && m == 0) {
            break;
        }
        std::unordered_map<std::string, int> ni;
        //std::unordered_map<int, std::string> in;
        // std::unordered_map<int, std::unordered_set<int>> hates;
        bool hates[16][16] = {false};
        int count = 1; 
        for (int i = 0; i < m; i++) {
            std::string a, b;
            std::cin >> a;
            std::cin >> b;
            if (ni.find(a) == ni.end()) {
                ni[a] = count;
                //in[count] = a;
                count++;
            }
            if (ni.find(b) == ni.end()) {
                ni[b] = count;
                //in[count] = b;
                count++;
            }
            hates[ni[a]][ni[b]] = true;
            hates[ni[b]][ni[a]] = true;
        }
        int total_teams = 10000000;
        // std::vector<std::unordered_set<int>> teams; 
        std::vector<std::vector<int>> teams;
        bool flag = true;
        total_teams = std::min(total_teams, do_backtrack(teams, hates, 1, 0, 10000000, n));
        
        std::cout << total_teams << std::endl;

    }

}