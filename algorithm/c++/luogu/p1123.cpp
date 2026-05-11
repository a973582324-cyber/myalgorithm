#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct st{
    int num;
    int t;
};
bool cmp(const st &a,const st &b){
    if(a.t==b.t)
    return a.num<b.num;
    return a.t<b.t;
}
int main(){
    int n;
    cin>>n;
    st t[1005];
    double time=0.0;
    for(int i=1;i<=n;i++){
        t[i].num=i;
        cin>>t[i].t;
    }
    sort(t+1,t+n+1,cmp);
    if(n>=2)
    for(int i=2;i<=n;i++){
        t[i].t+=t[i-1].t;
        time+=(double)t[i-1].t;
    }
    if(n>=2)
    time/=n;   
    for(int i=1;i<=n;i++){
        cout<<t[i].num<<' ';
    }
    cout<<endl;
    printf("%.2lf",time);
}