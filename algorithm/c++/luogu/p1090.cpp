#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[20005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0;
    int num=0;
    for(int i=1;i<n;i++){
        a[i]+=a[i-1];
    }
    cout<<a[n-1]+a[n-2];
}