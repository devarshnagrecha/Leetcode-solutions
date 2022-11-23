class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int checkRow[9][9] = {0}, checkColumn[9][9] = {0}, checkBox[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(checkRow[i][num] || checkColumn[j][num] || checkBox[k][num])
                        return false;
                    checkRow[i][num] = checkColumn[j][num] = checkBox[k][num] = 1;
                }
        
        return true;
    }
};