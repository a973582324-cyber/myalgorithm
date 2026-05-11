#include<iostream>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    int a[15];
    while(t--){
        int d[15]={0};
        cin>>n;
        int ans=0;
        int index=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[index]<a[i])
            index=i;
        }
        for(int i=1;i<=n;i++){
            if(a[i]==a[index])
            ans++;
            
        }
       
        cout<<ans<<endl;
    }
}