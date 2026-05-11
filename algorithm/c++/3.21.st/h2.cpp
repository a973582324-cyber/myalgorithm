#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int>ans;
    int temp=1e6;
    int n,m,l,r;
    int num[1000005];
    cin>>n>>m;
    int a[2005]={0};
    int k=0;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        if(!a[num[i]])
        k++;
        a[num[i]]++;
        ans.push(i);
        while(a[num[ans.front()]]>1&&!ans.empty())
        {
            a[num[ans.front()]]--;
            ans.pop();
        }
        if(k==m)
            if(ans.size()<temp)
            {
                temp=ans.size();
                l=ans.front();
                r=ans.back();
            }
    }
    cout<<l<<' '<<r;

}