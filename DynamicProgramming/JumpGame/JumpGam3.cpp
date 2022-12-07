#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>

using namespace std;



bool canJump(vector<int> &nums)
{
    int num_len = size(nums);
    if (num_len == 1)
    {
        return true;
    }

    int j = num_len - 2; // last but one index
    int last_true = 10e6;

    bool res;
    if (nums[j] > 0)
    {
        res = true;
        last_true = j;
    }
    else
    {
        res = false;
    }
    int last_index = size(nums) - 1;
    for (int i = j - 1; i >= 0; i--)
    {
        if (nums[i] == 0)
        {
            res = false;
            continue;
        }
        if (nums[i] >= last_index - i)
        {
            res = true;
            last_true = i;
            continue;
        }

        if (nums[i] + i >= last_true)
        {
            res = true;
            last_true = i;
            continue;
        }
        else
        {
            res = false;
            continue;
        }
    }
    return res;
}

int main()
{
    vector<int> aa = {3, 0, 2, 2, 0, 0, 1};
    cout << canJump(aa);

    return 0;
}