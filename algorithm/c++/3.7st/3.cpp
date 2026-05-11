#include<iostream>
#include<string>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
    string s;
        cin>>n;
        cin>>s;
        int ans=0;
        s='1'+s+'1';
        int l=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){
                if(s[i-1]=='1')
                    l=i;
                if(s[i+1]=='1'){
                    int a=(l==1)+(i==n);
                    ans+=(i-l+1+a)/3;
                }
            }
            if(s[i]=='1')
                ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}