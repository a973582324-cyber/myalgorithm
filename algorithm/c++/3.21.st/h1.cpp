#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[1000000];
    int b[2003];//记录出现次数
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k=0,i=0;//k用于记录出现画师的個數，i为计数器
    int r=-1,l=0,ans1,ans2;//r为右指针r为-1确保指向边界，l为左指针
    while(k!=m){
        if(b[a[i]]==0)k++;
        b[a[i]]++;
        r++;
        i++;
    }
    while(b[a[l]]>1)
        b[a[l++]]--;
    ans1=l;ans2=r;
    while(i<n){
        b[a[i]]++;
        r++;
        i++;
        while(b[a[l]]>1)
            b[a[l++]]--;
        if(ans2-ans1>r-l){
            ans2=r;
            ans1=l;
        }
    }
    cout<<ans1+1<<' '<<ans2+1;
}