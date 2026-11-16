#include<bits/stdc++.h>
using namespace std;

// 双指针模板：通过维护左右边界，把重复扫描压缩为一次线性扫描。
// 约定：longestUnique 可处理无序数组；twoSum 要求数组已经升序。

//求最长不重复连续子数组，时间复杂度O(n)
int longestUnique(vector<int>&a)
{
    unordered_map<int,int>count;
    int left = 0;
    int ans = 0;
    for(int right = 0;right<a.size();right++)
    {
        count[a[right]]++;
        while(count[a[right]]>1)
        {
            count[a[left]]--;
            left++;
        }
        ans = max(ans,right-left+1);
    }
    return ans;
}

//有序数组两数之和
pair<int,int> twoSum(vector<int>&a,int target)
{
    int left = 0,right = a.size()-1;
    while(left<right)
    {
        int sum = a[left]+a[right];
        if(sum==target)return {left,right};
        if(sum<target)left++;
        else right--;
    }
    return {-1,-1};
}

int main()
{
    return 0;
}
