#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int>best_pos (size(nums));

    int last_index = size(nums) - 1;
    best_pos[last_index] = 1;
    int largest = 1;
    for (int i = last_index - 1; i >= 0; i--){
        int largest_val_j = 1;
        for (int j = i + 1; j <= last_index; j++){
            if (nums[i] < nums[j] && (best_pos[j] + 1) > largest_val_j){
                largest_val_j = best_pos[j] + 1;
            }
        }
        best_pos[i] = largest_val_j;
        if(best_pos[i] > largest){
            largest = best_pos[i];
        }
    }
    return largest;


}
// [10,9,2,5,3,7,101,18]
int main (){ // t = O(n2) s = O(n)
    vector<int>input = {0};
    lengthOfLIS(input);
}