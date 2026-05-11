#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int x;
    for(int i=0;i<m;i++){
        cin>>x;
        int left=1,right=n;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(a[mid]>=x)
            right=mid-1;
            else if(a[mid]<x)
            left=mid+1;
            
        }
        if(a[left]==x)
        ans=left;
        cout<<ans<<endl;
    }
}