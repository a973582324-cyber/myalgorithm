//移动零，双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0,slow = 0;
        while(fast < nums.size())
        {
            if(nums[fast]!=0)
            nums[slow++] = nums[fast];
            fast++;
        }
        for(int i = slow;i<nums.size();i++)
        {
            nums[i] = 0;
        }
    }
};