#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    int a[15];
    while(t--){
        cin>>n;
        int index=0,ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int temp=0;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                temp=1;
                break;
            }
        }
        if(temp==0)
        cout<<n<<endl;   
        else
        cout<<1<<endl;     
    }
}