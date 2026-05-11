#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n;
    int a[105];
    while(t--){
        cin>>n;
        int temp=0,count=0;;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]%2==i%2){
                count++;
            }
            
        }
        for(int i=1;i<=n;i++)
        if(a[i]%2!=i%2){
                temp=1;
                break;
        }
        if(n%2==0&&count==0){
            temp=0;
        }
        if(!temp)
        cout<<"yes"<<endl;
        else
        cout<<"no"<<endl;
    }
}