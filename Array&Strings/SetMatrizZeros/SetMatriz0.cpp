#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    unordered_set<int>zero_row;
    unordered_set<int>zero_column;
    for (int i = 0; i < matrix.size(); i ++){

        for (int j = 0; j < matrix[i].size(); j ++){
            if (matrix[i][j] == 0){
                zero_row.insert(i);
                zero_column.insert(j);
            }
        }
    }

    for (auto &row : zero_row){
        for (int j = 0; j < matrix[row].size(); j++){
            matrix[row][j] = 0;
        }
    }
    for (int i = 0; i < matrix.size(); i ++){
        for (auto &column : zero_column){
            matrix[i][column] = 0;

        }
    }
}

int main(){
    vector<vector<int>> matrix = {{1,0,1}, {0,0,0}, {1,-1,1}};
    setZeroes(matrix);
}