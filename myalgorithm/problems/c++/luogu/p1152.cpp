#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[1005];
    int b[1005];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++)b[i]=abs(a[i]-a[i-1]);
    sort(b+1,b+n);
    for(int i=1;i<n;i++)
    {
        if(b[i]!=i){
            cout<<"Not jolly";
            return 0;
        }
    }
    cout<<"Jolly";
}