#include <vector>

class TicTacToe {
public:
    std::vector<int> rows_x;
    std::vector<int> cols_x;
    std::vector<int> diags_x;
    std::vector<int> rows_o;
    std::vector<int> cols_o;
    std::vector<int> diags_o;
    int n;
    TicTacToe(int n) {
        this -> n = n;
        rows_x = std::vector<int>(n, n);
        cols_x = std::vector<int>(n, n);
        diags_x = std::vector<int>(2, n);
        rows_o = std::vector<int>(n, n);
        cols_o = std::vector<int>(n, n);
        diags_o = std::vector<int>(2, n);
    }
    int move(int row, int col, int player) {
        if (player == 1) {
            rows_x[row]--;
            cols_x[col]--;
            if (row == col) {
                diags_x[0]--;
            }
            if (row == n - col - 1) {
                diags_x[1]--;
            }
            if (rows_x[row] == 0 || cols_x[col] == 0 || diags_x[1] == 0 || diags_x[0] == 0) {
                return 1;
            }
            
        } else {
            rows_o[row]--;
            cols_o[col]--;
            if (row == col) {
                diags_o[0]--;
            }
            if (row == n - col - 1) {
                diags_o[1]--;
            }
            if (rows_o[row] == 0 || cols_o[col] == 0 || diags_o[1] == 0 || diags_o[0] == 0) {
                return 2;
            }
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */