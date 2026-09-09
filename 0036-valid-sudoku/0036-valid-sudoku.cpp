class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for(int r = 0; r < 9; r++){
            for(int c =0; c < 9; c++){
                char val = board[r][c];
                if (val == '.') continue;
                int boxIndex = (r/3) * 3 + (c/3);
                string rowkey = "row" + to_string(r) + val;
                string colkey = "col" + to_string(c) + val;
                string boxkey = "box" + to_string(boxIndex) + val;
                if (seen.count(rowkey) || seen.count(colkey) || seen.count(boxkey)){
                    return false;
                }
                seen.insert(rowkey);
                seen.insert(colkey);
                seen.insert(boxkey);
            }
        }
        return true;
    }
};