#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int temp=0;
        vector<int>p(n);
        vector<int>s(n);
        for(int i=0;i<n;i++)
            cin>>p[i];
        for(int i=0;i<n;i++)
            cin>>s[i];
        int count1=0,count2=0;
        for(int i=n-1;i>0;i--){
            count1++;
            if(p[i]!=p[i-1])
                break;
        }
        for(int i=0;i<n-1;i++){
            count2++;
            if(s[i+1]!=s[i])
                break;
        }
        for(int i=0;i<n;i++){
            if(p[i]%s[i]!=0&&s[i]%p[i]!=0)
                temp=1;
        }
        if(p[n-1]!=s[0]||count1+count2!=n+1)
            temp=1;
        if(temp)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
}