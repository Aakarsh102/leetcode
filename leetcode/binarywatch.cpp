#include <vector>
#include <string>
class Solution {
public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<int> vals = {8,4,2,1,32,16,8,4,2,1};
        std::vector<std::string> result;

        std::function<void(int, int, int, int)> backer = [&](int led, int on, int hours, int mins) {
            if (led > 10 - on) {
                return;
            }
            if (on == 0) {
                if (hours >= 0 && hours < 12 && mins >= 0 && mins < 60) {
                    if (mins < 10) {
                        result.push_back(std::format("{}:0{}", hours, mins));
                        return;
                    } 
                    result.push_back(std::format("{}:{}", hours, mins));
                    return;
                }
                return;
            }
            if (led < 4) {
                backer(led + 1, on - 1, hours + vals[led], mins);
            } else {
                backer(led + 1, on - 1, hours, mins + vals[led]);
            }
            backer(led + 1, on, hours, mins);
            return;
        };

        backer(0, turnedOn, 0, 0);
        return result;
    }
};