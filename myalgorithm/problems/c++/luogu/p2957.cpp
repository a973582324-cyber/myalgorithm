#include<iostream>
#include<algorithm>
using namespace std;
int dp[85][85];
int main(){
    string a,b;
    cin>>a>>b;
    int max_=0;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=0;
            max_=max(dp[i][j],max_);
        }
    }
    cout<<max_;
}