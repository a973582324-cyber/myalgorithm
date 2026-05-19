//打家劫舍
class Solution {
public:
    int rob(vector<int>& nums) {
        long long ans = 0;
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return nums[0];
        int a = nums[0];
        int b = max(nums[0],nums[1]);
        for(int i = 2;i<nums.size();i++)
        {
            int temp = b;
            b = max(b,a+nums[i]);
            a = temp;
        }
        return b;
    }
};