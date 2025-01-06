class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        std::function<void(std::string, int, int)> gen = [&] (std::string sub, int open, int close) {
            if (close == n) {
                result.push_back(sub);
                return;
            }
            else if (open < n) {
                gen(sub + '(', open + 1, close);
            }
            if (close < open) {
                gen(sub + ')', open, close + 1);
            }
        };
        gen("", 0, 0);
        return result;
        
    }
};