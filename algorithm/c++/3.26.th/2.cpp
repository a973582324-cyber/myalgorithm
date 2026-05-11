#include<iostream>
#include<stack>
using namespace std;
int main(){
    int t;
    cin>>t;
    int a[5];
    while(t--){
        int sum=0;
        for(int i=0;i<3;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2!=0){
        cout<<-1<<endl;
        continue;
        }
        int ans=0;
        int temp=a[0]+a[1];
        if(temp<a[2])
        ans=temp;
        else{
            if((temp-a[2])%2==0)
            ans=a[2]+(temp-a[2])/2;
            else
            ans=a[2]-1;
        }
        cout<<ans<<endl;
    }
}