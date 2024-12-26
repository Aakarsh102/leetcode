#include <string>
class Solution {
public:
    std::string intToRoman(int num) {
        std::pair<int, std::string> romanMap[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    std::string k = "";
    for (std::pair<int, std::string> i : romanMap) {
        while (num >= i.first) {
            k += i.second;
            num -= i.first;
        }
    }

    return k;
    }
};