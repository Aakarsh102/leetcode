#include <string>
class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<std::string, int> romanmap = 
        { {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
        {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
        {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1} };

        
        int num = 0;
        int i = 0;
        int len = s.length();
        while (i < len) {
            if (i == len-1) {
                num += romanmap[std::string(1, s[i])];
                i++;
                continue;
            }

            if (romanmap[std::string(1,s[i])] < romanmap[std::string(1, s[i+1])]) {
                num+=  romanmap[std::string(1, s[i]) + std::string(1, s[i+1])];
                i += 2;
            }    
            else {
                num += romanmap[std::string(1, s[i])];
                i++;
            }
        }
        return num;
    }
};