#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;

int pathMaker(int m, int n, int f_m, int f_n){
    if (f_m > m - 1  || f_n > n - 1){
        return 0;
    }
    else if (f_m == m - 1 && f_n == n - 1){
        return 1;
    }
    else if (map[f_m][f_n] != -1){
        return map[f_m][f_n];
    }

    return map[f_m][f_n] =  pathMaker(m, n , f_m + 1, f_n) + pathMaker(m, n, f_m, f_n + 1);
}

int uniquePaths(int m, int n) {
   map.resize(m, vector<int>(n, - 1));
   int res = pathMaker(m, n, 0 , 0);
   return res;
}

int main(){
    cout << uniquePaths(3, 2);
}