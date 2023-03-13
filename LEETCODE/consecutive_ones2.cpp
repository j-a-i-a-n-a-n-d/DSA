#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countConsecutiveOnes(vector<int> &nums, int k)
    {
        int ans = 0;
        int countZeroes = 0;
        int i = 0, j = 0;
        int n = nums.size();

        while (i < n)
        {
            if (!nums[i++])
                countZeroes++;
            while (countZeroes > k)
            {
                if (!nums[j])
                    countZeroes--;
                j++;
            }
            ans = max(i - j, ans);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    // k = 100 in this case
    cout << sol.countConsecutiveOnes(nums, 100) << endl;
}