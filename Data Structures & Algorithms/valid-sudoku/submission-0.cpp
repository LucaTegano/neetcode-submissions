class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<string, unordered_set<char>> squares;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                char num = board[r][c];

                if (rows[r].find(num) != rows[r].end() || 
                    cols[c].find(num) != cols[c].end() || 
                    squares[to_string(r / 3) + "," + to_string(c / 3)].find(num) != squares[to_string(r / 3) + "," + to_string(c / 3)].end())
                    return false;

                rows[r].insert(num);
                cols[c].insert(num);
                squares[to_string(r / 3) + "," + to_string(c / 3)].insert(num);
            }
        }
        return true;
    }
};