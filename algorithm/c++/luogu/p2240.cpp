#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct coin{
    int m;
    int n;
    double av;
};
bool cmp(const coin &a,const coin &b){
    return a.av>b.av;
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<coin>a(n);
    double ans=0.0;
    for(int i=0;i<n;i++){
        cin>>a[i].m>>a[i].n;
        a[i].av=(double)a[i].n/a[i].m;
    }
    sort(a.begin(),a.end(),cmp);
    int i=0;
    while(1){
        if(t-a[i].m>0){
            ans+=a[i].n;
            t-=a[i].m;
        }
        else{
            ans+=t*a[i].av;
            break;
        }
        if(i>=n)
            break;
        i++;
    }
    printf("%.2lf\n",ans);
}