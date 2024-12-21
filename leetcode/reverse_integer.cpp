
class Solution {
public:
    int reverse(int x) {
        std::string str = std::to_string(x);
        int len = str.length();
        if (len == 1) {
            return x;
        }
        std::string max = std::to_string(INT_MAX);
        std::string min = std::to_string(INT_MIN);
        int index = 0;
        if (x < 0) {
            index = 1;
        }
        
        while (index < len) {
            char temp = str[index];
            str[index] = str[len - 1];
            str[len - 1] = temp;
            len--;
            index++;
        }
        if (str.length() == max.length()) { 
            int comp = str.compare(max);
            if (comp > 0) {
                return 0;
            }
        }
        if (str.length() == min.length()) {
            int comp = str.compare(min);
            if (comp > 0) {
                return 0;
            }
        }
        return std::stoi(str);
        
    }
};