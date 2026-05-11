#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long ans=0;
    for(int i=1,num=1;i<=n;i++){
        num*=i;
        ans+=num;
    }
    cout<<ans<<endl;
    return 0;
}
//本题要用到高精度未解决