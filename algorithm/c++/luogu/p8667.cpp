#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100005
int a[MAX];
int b[MAX];
int c[MAX];
int n;
long long find1(int x,int *m){
    long long l = 0;
    long long r = n-1;
    while(l<=r){
        long long mid=(l+r)/2;
        if(x<=m[mid])
            r=mid-1;
        else
            l=mid+1;
    }
    return l;
}
long long find2(int x,int *m){
    long long l = 0;
    long long r = n-1;
    while(l<=r)
    {
        long long mid = (l+r)/2;
        if(x >= m[mid])
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}
int main(){
    cin>>n;
    long long ans=0;
    for(int i = 0;i<n;i++)cin>>a[i];
    for(int i = 0;i<n;i++)cin>>b[i];
    for(int i = 0;i<n;i++)cin>>c[i];
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    for(int i = 0;i<n;i++){
        long long num1 = find1(b[i],a);
        long long num2 = find2(b[i],c);
        ans += (num1)*(n-num2);
    }
    cout<<ans<<endl;
}