#include <string>
class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        bool changed = true;
        int rkill = 0;
        int dkill = 0;
        char cur = '0';
        while (changed) {
            changed = false;
            for (int i = 0; i < senate.length(); i++) {
                cur = senate[i];
                if (cur == 'R') {
                    if (rkill > 0) {
                        rkill--;
                        senate[i] = 'k';
                        changed=true;
                        continue;
                    }
                    dkill++;
                } else if (cur == 'D') {
                    if (dkill > 0) {
                        dkill--;
                        senate[i] = 'k';
                        changed=true;
                        continue;
                    }
                    rkill++;
                }
            }
        }
        for (char i : senate) {
            if (i == 'k') {
                continue;
            }
            return i == 'R' ? "Radiant" : "Dire";
        }
        return "bro something is wrong";
    }
};