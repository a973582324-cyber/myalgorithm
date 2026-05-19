//hs表实现的两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hashmap;
        vector<int>a(2);
       for(int i=0;i<nums.size();i++){
        auto it=hashmap.find(target-nums[i]);
        if(it!=hashmap.end()){
            a[0]=it->second;
            a[1]=i;        
        }
        hashmap[nums[i]]=i;
       }
       return a;
    }
};