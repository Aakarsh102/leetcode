#include <string>
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        std::string str = "";
        int row = numRows;

        int index = 0;
        int length = s.length();
        for (row; row > 0; row--) {
            index = numRows - row;
            while (index < length) {
                str += s[index];
                index = index + 2 * row - 2;
                if (index < length && row != numRows && row != 1) {
                    str += s[index];
                }
                index += 2 * (numRows - row);

            }

        }
        return str;
        
    }
};