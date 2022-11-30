#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int Partition(vector<int> &unique, unordered_map<int, int> hash, int init, int end)
{
    int store_index = init;
    // pivot = j
    for (int i = init; i <= end; i++)
    {
        if (hash[unique[i]] >= hash[unique[end]])
        {
            swap(unique[i], unique[store_index]);
            store_index++;
        }
        else
        {
            continue;
        }
    }
    swap(unique[store_index], unique[end]);

    return store_index; // real position
}

void quickSelect  (int init, int end, vector<int>&unique, unordered_map<int, int> hash, int k){

    if (init == end){
        return;
    }
    // pivot = right

    int pivot_index = Partition(unique, hash, init, end);

    if (k == pivot_index){
        return;
    }
    else if(k < pivot_index){
        quickSelect(init, pivot_index- 1, unique, hash, k);
    }
    else{
        quickSelect(pivot_index + 1, end, unique, hash, k);

    }

}

vector<int> topKFrequent(vector<int> nums, int k)
{
    unordered_map<int, int> mapper;
    int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        mapper[nums[i]]++; // maps frequency
    }
    vector<int> unique;
    for (auto pair : mapper)
    {
        unique.push_back(pair.first);
    }
    int mapper_size = mapper.size();

    quickSelect(0, mapper_size - 1, unique, mapper, mapper_size-k);
    vector<int>res(k);
    copy(unique.begin(), unique.end() - (mapper_size - k), res.begin());
    return res;

}   

int main()
{
    // Return the kth most frequent numbers in the array

    topKFrequent({1, 1, 1, 3, 2, 2, 4, 4, 4, 4, 5, 5}, 2);
    return 0;
}