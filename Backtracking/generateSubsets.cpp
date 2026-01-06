#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void subset(int index, vector<int> &nums,
                vector<int> &curr, vector<vector<int>> &res)
    {

        res.push_back(curr);

        for (int i = index; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);        // choose
            subset(i + 1, nums, curr, res); // explore
            curr.pop_back();                // backtrack
        }
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> res;
    vector<int> curr;

    obj.subset(0, nums, curr, res);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "], ";
    }
    cout << "]";

    return 0;
}
