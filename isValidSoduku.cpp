//https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool grids[9][9] = {false};

        for(int i=0; i<9 ;i++){
            for(int j = 0; j< 9 ;j++){
                if(board[i][j]=='.') continue;

                int idx = board[i][j]-'0'-1;
                int gridnum = (i/3)*3+(j/3);

                if(rows[i][idx]||cols[j][idx]||grids[gridnum][idx]) return false;
                else{
                    rows[i][idx] = true;
                    cols[j][idx] = true;
                    grids[gridnum][idx] = true;
                }
            }
        }

        return true;
    }
};