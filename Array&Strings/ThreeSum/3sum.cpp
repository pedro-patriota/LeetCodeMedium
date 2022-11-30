#include <iostream>
#include <vector>
using namespace std;
#include <map>
#include <unordered_map>
#include <algorithm>

vector <vector<int>> threeSum(vector<int>& A){

    if (A.size() < 3){
        return {};
    }
    sort(A.begin(), A.end());
    if (A[0] > 0){
        return {};
    }

    unordered_map<int, int>freq;
    vector <vector<int>> counter;

    int complement, s_complement, target = 0;

    for (int i = 0; i <A.size(); i++){
        freq[A[i]] = i;
    }

    for (int i =0; i <A.size(); i++){

        if (A[i] > 0){
            break;
        }
        complement = target - A[i];        

        for (int j = i + 1; j < A.size(); j++){
            s_complement = complement - A[j];

            if (freq.count(s_complement) > 0 && freq.find(s_complement)->second > j){
                counter.push_back({A[i], A[j], s_complement});
            }
            j = freq.find(A[j])->second; // Gets the next different value
           

        }
        
        i = freq.find(A[i])->second; // Gets the next different value

       
    }
    return counter; 
}

int main(){
    vector<int>A = {0,0,0}; //  -2 -1 -1  0  1 2 
    vector<vector<int>>B = threeSum(A);
    cout << '[';
    for (int i = 0; i < B.size(); i++){
        cout << '[';
        for (int j = 0; j <= 2; j++){
            j != 2 ? cout << B[i][j] << ',':cout << B[i][j];
        }
        cout << ']';
    }
    cout << ']';
    return 0;
}