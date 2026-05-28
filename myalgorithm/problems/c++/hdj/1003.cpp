#include<stdio.h>

int main(void)
{
    int t, i;
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        int n, j, a;
        int maxsum = -1001, start = 0, end = 0, sum = 0, temp = 1;
        //题目上说测试数据范围是-1000-1000所以数列最大总和初始化为-1001绝对没问题。
        //题目上数列是从1开始下标的所以temp初始化为1.temp用于临时记录相关元素下标。
        scanf("%d", &n);
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a);
            sum += a;//计算当前数列总和
            if (sum > maxsum)//发现总和为更大的数列
            {
                start = temp;//记录当前和为最大的子序列开始与结束的下标位置
                end = j;
                maxsum = sum;//存储当前总和为最大的子序列
            }
            if (sum < 0)//发现导致序列和为负数的子序列
            {
                sum = 0;//当前数据列和假定为0，寻找下一个正数元素，也就是你建立和为正数的元素子序列
                temp = j + 1;//丢弃此序列前的所有元素，记录位置
            }
        }
        printf("Case %d:\n%d %d %d\n", i, maxsum, start, end);
        if (i != t)//按题目要求格式输出
            printf("\n");
    }
    return 0;
}