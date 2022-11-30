#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

int directionX[] = {1, -1, 0, 0};
int directionY[] = {0, 0, 1, -1};
bool recursive(vector<vector<char>>board, string word, int row, int column, int index, vector<vector<int>>& visited, int x, int y)
{
    if (x > row || y > column || x < 0 || x <0) return false;
    if(board[x][y] != word[index])return false;
    if(visited[x][y]) return false;
    if (index == word.length() -1) return true;

    // I can visit!
    visited[x][y] = 1;
    for (int i =0; i < 4; i++){
        int new_x =x+ directionX[i];
        int new_y = y +  directionY[i];
        if (recursive(board, word, row, column, index+1, visited, new_x, new_y) == true) return true;
    }
    visited[x][y] = 0;
        return false;

}

bool exist(vector<vector<char>> &board, string word)
{
    int m, n;
    m = board.size();
    n = board[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0)); 
    bool res = false;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0])
            {
                if (recursive(board, word, m -1, n-1, 0, visited, i, j)){
                    return true;
                }
            }
        }
    }
  

  
    return res;
}

int main()
{
    vector<vector<char>> a = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    bool b = exist(a, "SEE");
    cout << b;
    return 0;
}