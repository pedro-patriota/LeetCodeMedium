#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int max_row = matrix[0].size();
    bool zerarFirstRow = false, zerarFirstCol = false;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < max_row; j++)
        {
            if (matrix[i][j] == 0)
            {
                if(i == 0) zerarFirstRow = true;
                if(j == 0) zerarFirstCol = true;
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < max_row; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (zerarFirstRow){
        for (int j = 0; j < max_row; j ++){
            matrix[0][j] = 0;
        }
    }
    if (zerarFirstCol){
        for (int i = 0; i < matrix.size(); i ++){
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 0, 1}, {0, 0, 0}, {1, -1, 1}};
    setZeroes(matrix);
    return 0;
}