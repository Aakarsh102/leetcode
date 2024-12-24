#include <regex>
#include <string>
class Solution {
public:
    int myAtoi(std::string s) {
        // regex b(" *[+-]?[0-9]+");
        // if (!regex_match(s, b)) {
        //     return 0;
        // }
        // std::smatch match_obj;
        // std::regex_search(s, match_obj, b);
        // return stoi(match_obj[0]);
        int i = 0;
        while (i < s.size() && isspace(s[i])) {
            i++;
        }

        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        long long result = 0;
        while (i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Check for overflow/underflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return result * sign;

    }
};