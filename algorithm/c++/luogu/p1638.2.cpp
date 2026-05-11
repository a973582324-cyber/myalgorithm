#include<iostream>
using namespace std;
int a[20003];int num[1000003];
int main(){
    int n,m;
    int k=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>num[i];
    int ll,rr;
    int l=1,r=1,ans=1e6;
    a[num[1]]=1;
    while(l<=r&&r<=n){
        if(k==m){
           if(r-l-1<ans){
            ans=r-l-1;
            ll=l;
            rr=r;
           } 
           a[num[l]]--;
           if(a[num[l]]==0)
           k--;
           l++;
        }
        else{
            r++;
            a[num[r]]++;
            if(a[num[r]]==1)
            k++;
        }
    }
    cout<<ll<<' '<<rr;
}