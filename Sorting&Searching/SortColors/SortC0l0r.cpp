#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

void sortColors(vector<int> &nums)
{
    vector<int> red;
    vector<int> blue;
    vector<int> white;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            red.push_back(nums[i]);
        }
        else if (nums[i] == 1)
        {
            white.push_back(nums[i]);
        }
        else
        {
            blue.push_back(nums[i]);
        }
    }
    nums.clear();
    nums.insert(nums.end(), red.begin(), red.end());
    nums.insert(nums.end(), white.begin(), white.end());
    nums.insert(nums.end(), blue.begin(), blue.end());
}

int main()
{
    return 0;
}