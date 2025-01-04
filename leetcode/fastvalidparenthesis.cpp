#include <string>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
        std::vector<char> stack;
        int n = 0;
        while (n < s.length()) {
            if (stack.size() > 0) {
                switch (stack.back()) {
                    case '(':
                        if (s[n] == ']' || s[n] == '}') {
                            return false;
                        }
                        s[n] == ')' ? stack.pop_back() : stack.push_back(s[n]);
                        break;
                    case '{':
                        if (s[n] == ')' || s[n] == ']') {
                            return false;
                        }
                        s[n] == '}' ? stack.pop_back() : stack.push_back(s[n]);
                        break;
                    case '[':
                        if (s[n] == ')' || s[n] == '}') {
                            return false;
                        }
                        s[n] == ']' ? stack.pop_back() : stack.push_back(s[n]);
                }
                // stack.pop_back();
                n++;
                continue;
            }
            if (s[n] == ']' || s[n] == ')' || s[n] == '}') {
                return false;
            }
            stack.push_back(s[n]);
            n++;
        }
        return stack.empty();
    }
};