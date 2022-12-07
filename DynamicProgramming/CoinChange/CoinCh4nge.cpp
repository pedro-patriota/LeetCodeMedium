#include <iostream>
#include <vector>

using namespace std;


int coinChange(vector<int> &coins, int amount)
{
    vector<int> best_pos(amount + 1, INT_MAX);
    best_pos[0] = 0;

    for (int i = 1; i <= amount; i++)
    {

        for (auto j : coins)
        {
            if (i >= j)
            {
                int change = i - j;
                if (best_pos[change] != INT_MAX && best_pos[change] + 1 < best_pos[i]){
                    best_pos[i] = best_pos[change] +1;
                }
            }
        }
    }
    if (best_pos[amount] == INT_MAX){
        return -1;
    }
    return best_pos[amount];
}

int main()
{
}