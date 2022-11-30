#include <iostream>
#include <unordered_map>
using namespace std;
#include <vector>
#include <string>

vector<string> letterCombinations(string digits) {

    unordered_map <int, vector<char>> alfa;
    alfa[2] = {'a', 'b', 'c'};
    alfa[3] = {'d', 'e', 'f'};
    alfa[4] = {'g', 'h', 'i'};
    alfa[5] = {'j', 'k', 'l'};
    alfa[6] = {'m', 'n', 'o'};
    alfa[7] = {'p', 'q', 'r', 's'};
    alfa[8] = {'t', 'u', 'v'};
    alfa[9] = {'w', 'x', 'y', 'z'};

    if (digits.length() == 0){
        return {};
    }
    int size = 1;
    for (int i = 0; i < digits.length(); i ++){
        int num =  digits[i] - '0';
        size *= alfa[num].size();
    }
    vector<string> res (size);

    for (int i = 0; i < digits.length(); i ++){
        int num =  digits[i] - '0';
        // num = 2
        int intra_size = size/alfa[num].size();
        for (int j = 0; j < res.size(); j++){

            res[j] += alfa[num][(j/intra_size)%alfa[num].size()];
        }
        size = size/alfa[num].size();
    
    }
    return res;
}

int main (){

    vector<string> a = letterCombinations("234");

    for (int i = 0; i<a.size(); i ++){
        cout << a[i] << " ";
    }
    return 0;
}