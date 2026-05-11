#include<iostream>
using namespace std;
long long a[5000]={0};
long long add(int n){
    if(n==1)
    return 1;
    else if(n==2)
    return 2;
    else{
       if(a[n]==0)
       a[n]=add(n-1)+add(n-2);
       return a[n];
    }
}
int main(){
    int n;
    cin>>n;
    long long ans=add(n);
    cout<<ans<<endl;
    return 0;
}