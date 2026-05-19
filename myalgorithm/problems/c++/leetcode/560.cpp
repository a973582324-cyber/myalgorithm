//和为k的子数组 前缀和加哈希表优化
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>hs;
        hs[0] = 1;
        int count = 0,pre = 0;
        for(auto &a:nums)
        {
            pre+=a;
            if(hs.count(pre-k))
            {
                count += hs[pre-k];
            }
            hs[pre]++;
        }
        return count;
    }
};