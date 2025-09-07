#include <vector>
#include <string>
class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::vector<std::string> stack;
        int sum = 0;
        int one = 0;
        int two = 0;
        for (std::string i : tokens) {
            if (i == "-" || i == "+" || i == "*" || i == "/") {
                one = std::stoi(stack.back());
                stack.pop_back();
                two = std::stoi(stack.back());
                stack.pop_back();
                if (i == "-") {
                    stack.push_back(std::to_string(two - one));
                } else if (i == "+") {
                    stack.push_back(std::to_string(two + one));
                } else if (i == "*") {
                    stack.push_back(std::to_string(two * one));
                } else {
                    stack.push_back(std::to_string(two/one));
                }
                continue;
            }
            stack.push_back(i);
        }
        return std::stoi(stack.back());
    }
};