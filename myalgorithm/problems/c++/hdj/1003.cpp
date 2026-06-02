#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t, i;
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        int ans = -1001,l = 0,r = 0;
        int n;
        cin>>n;
        vector<int> a(n+1),b(n+1);
        for(int j = 1;j<=n;j++)
        {
            cin>>a[j];
            b[j] = a[j] + b[j-1];
        }
        int ll = 0;
        for(int j = 1;j<=n;j++)
        {
            if(b[j]-b[ll]>ans)
            {
                ans = b[j]-b[ll];
                r = j;
                l = ll + 1;
            }
            if(b[j] - b[ll]<0)
            {
                ll = j;
            }
        }
        printf("Case %d:\n%d %d %d\n", i, ans, l, r);
        if (i != t)//按题目要求格式输出
            printf("\n");
    }
    return 0;
}