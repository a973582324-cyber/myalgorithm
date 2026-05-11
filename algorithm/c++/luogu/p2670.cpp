#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string a[105];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=0;
            if(a[i][j]=='?'){
            if(i+1<n&&a[i+1][j]=='*')
                ans++;
            if(i+1<n&&j+1<m&&a[i+1][j+1]=='*')
                ans++;
            if(i+1<n&&j-1>=0&&a[i+1][j-1]=='*')
                ans++;
            if(j-1>=0&&a[i][j-1]=='*')
                ans++;
            if(j+1<m&&a[i][j+1]=='*')
                ans++;
            if(i-1>=0&&a[i-1][j]=='*')
                ans++;
            if(i-1>=0&&j-1>=0&&a[i-1][j-1]=='*')
                ans++;
            if(i-1>=0&&j+1<m&&a[i-1][j+1]=='*')
                ans++;
            a[i][j]='0'+ans;
            }
            cout<<a[i][j];
        }
        cout<<endl;
    }
}