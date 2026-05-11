#include<iostream>
using namespace std;
int st[15];
struct food
{
    int sol;
    int ku;
};
food a[15];
int ans=1e9;
int n;
void dfs(int x){
    if(x>n){
        int temp=0;
        int sum1=1,sum2=0;
        for(int i=1;i<=n;i++){
            if(st[i]==1){
            temp=1;
            sum1*=a[i].sol;
            sum2+=a[i].ku;
            } 
        }
        if(temp)
        ans=min(ans,abs(sum1-sum2));
        return;
    }
    st[x]=1;
    dfs(x+1);
    st[x]=0;

    st[x]=2;
    dfs(x+1);
    st[x]=0;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].sol>>a[i].ku;
    }
    dfs(1);
    cout<<ans<<endl;
}