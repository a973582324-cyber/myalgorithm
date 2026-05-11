#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t,n;
    cin>>t;
    int a[100005];
    int dp[100005]={0};
     while(t--)
    {
        cin>>n;
        int temp=0;
        vector<int>b;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1)
            temp=1;
        }
        sort(a,a+n);
        if(temp){
        cout<<"yes"<<endl;
        continue;
        }
        for(int i=1;i<n;i++){
            if(a[i]%a[0]!=0)
            b.push_back(a[i]);
        }
        sort(b.begin(),b.end());
        int len=b.size();
        for(int i=0;i<len;i++){
            if(b[i]%b[0]!=0){
                temp=1;
                break;
            }
        }
        if(temp)
        cout<<"no"<<endl;
        else
        cout<<"yes"<<endl;
    }
}