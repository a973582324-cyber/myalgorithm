//搜索二位矩阵，二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int t = n,m = matrix[0].size();
        for(int i = 0;i<n;i++)
        {
            if(target>=matrix[i][0]&&target<=matrix[i][m-1])
            {
                t = i;
                break;
            }
        }
        if(t==n)
            return false;
        int l = 0,r = m;
        while(r > l)
        {
            int mid = (l+r)/2;
            if(matrix[t][mid]==target)
                return true;
            else if(matrix[t][mid]>target)
                r = mid;
            else
                l = mid + 1;
        }
        return false; 
    }
};