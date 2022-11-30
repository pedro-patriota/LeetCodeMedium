#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>



using namespace std;

vector<int> topKFrequent(vector<int> nums, int k) {

    if (k == nums.size()){
        return nums;
    }

    map<int, int>table;
    int size = nums.size();

    for (int i = 0; i < size; i++){
        table[nums[i]]++;
    }           
    int table_size = table.size();
    unordered_map<int, int> :: iterator it;

    auto aux = [&table](int i, int j){
        return table[i] > table[j];
    };
        
    
    priority_queue<int, vector<int>,
    decltype (aux)> heap(aux);

    for (pair<int, int> it : table){
        heap.push(it.first);

       if (heap.size() > k){
            heap.pop();
        } 
    }
    vector<int>hash (k);
    
    for (int i = 0; i < k; i ++){
        hash[i] = heap.top();
        heap.pop();
    }
    return hash;

}

int main(){
    // Return the kth most frequent numbers in the array
    topKFrequent({1, 4, 1, 2, 2, 4, 1, 2, 3}, 2);
    return 0;
}