#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> sub_num;

    for (auto val : nums)
    {
        if (sub_num.empty() || val > sub_num[sub_num.size() - 1])
        {
            sub_num.push_back(val);
        }
        else
        {
            auto it = lower_bound(sub_num.begin(), sub_num.end(), val);
            *it = val;
        }
    }
    return sub_num.size();
}

int main()
{
    vector<int> input = {3, 5,2, 1, 7, 9, 4, 10};
    lengthOfLIS(input);
}