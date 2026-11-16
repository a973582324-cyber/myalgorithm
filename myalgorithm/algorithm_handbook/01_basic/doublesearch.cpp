// 二分查找模板：搜索区间是闭区间 [l,r]，数组必须按升序排列。
// 三个函数的时间复杂度均为 O(log n)。
#include<bits/stdc++.h>
using namespace std;

//在升序数组中查找target，找到返回下标，否则返回-1
int binarySearch(int l,int r,int a[],int target)
{
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(a[mid]==target)return mid;
        if(a[mid]<target)l = mid+1;
        else r = mid-1;
    }
    return -1;
}

//返回第一个大于等于target的位置，和lower_bound作用相同
int lowerBound(int l,int r,int a[],int target)
{
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(a[mid]>=target)r = mid-1;
        else l = mid+1;
    }
    return l;
}

//返回第一个大于target的位置，和upper_bound作用相同
int upperBound(int l,int r,int a[],int target)
{
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(a[mid]>target)r = mid-1;
        else l = mid+1;
    }
    return l;
}

int main()
{
    return 0;
}
