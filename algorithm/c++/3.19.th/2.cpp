#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct bank 
{
    long long money;
    long long out;
    long long sheng;
};
bool cmp(bank &a,bank &b){
    if(a.sheng==b.sheng){
        return a.money>b.money;
    }
    return a.sheng>b.sheng;
}
int main(){
    long long t,n,x,y;
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        vector<bank>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].money;
            a[i].out=y*(a[i].money/x);
            a[i].sheng=a[i].money%x;
        }
        sort(a.begin(),a.end(),cmp);
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=a[i].out;
        }
        long long max_=0;
        for(int i=0;i<n;i++){
            long long temp=ans-a[i].out+a[i].money;
            max_=max(temp,max_);
        }
        cout<<max_<<endl;
    }
    
}