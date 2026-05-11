#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct tag 
{
    long long l;
    long long r;
    long long real;
};
bool cmp(const tag &a,const tag &b){
    return a.real>b.real;
}
int main(){
    long long t,n,k;
    cin>>t;
    long long ans;
    while(t--){
        cin>>n>>k;
        vector<tag>a(n);
        vector<int>b(n,-1);
        for(int i=0;i<n;i++){
            cin>>a[i].l>>a[i].r>>a[i].real;

        }
        sort(a.begin(),a.end(),cmp);
        for(int i=0,j=0;i<n;i++){
             if(k>=a[i].l&&k<=a[i].r){
                b[j]=i;
                j++;
            }
        }
        int i=0;
        while(b[i]!=-1){
            long long max_=max(a[b[i]].real,k);
            int find=0;
            while(1){
                for(int j=0;j<n;j++){
                    if(a[b[j]].real>=a[j].l&&a[b[j]].real<=a[j].r){
                        max_=max(max_,a[j].real);
                        find=1;
                    }
                }

            }
            i++;
        }
        cout<<ans<<endl;
    }
}