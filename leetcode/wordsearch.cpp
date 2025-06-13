#include <vector>
#include <string>
class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();
        bool ret = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret = do_search(board, i, j, 0, word, 0);
                if (ret == true) {
                    return true;
                }
            }
        }
        return false;
    }

    bool do_search(std::vector<std::vector<char>>& board, int i, int j, int index, std::string& word, int block) {
        if (index == word.length()) {
            return true;
        }
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0) {
            return false;
        }
        if (board[i][j] != word[index]) {
            return false;
        }
        else {
            bool ret = false;
            char store;
            if (block != 2) {
                store = board[i][j];
                board[i][j] = '1';
                ret = do_search(board, i + 1, j, index + 1, word, 4);
                board[i][j] = store;
            }
            if (ret == false && block != 1) {
                store = board[i][j];
                board[i][j] = '1';
                ret = do_search(board, i, j + 1, index + 1, word, 3);
                board[i][j] = store;
            }
            if (ret == false && block != 4) {
                store = board[i][j];
                board[i][j] = '1';
                ret = do_search(board, i - 1, j, index + 1, word, 2);
                board[i][j] = store;
            }
            if (ret == false && block != 3) {
                store = board[i][j];
                board[i][j] = '1';
                ret = do_search(board, i, j - 1, index + 1, word, 1);
                board[i][j] = store;
            }
            if (ret == true) {
                return true;
            } else {
                return false;
            }
        }

    }
};