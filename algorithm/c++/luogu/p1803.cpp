#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ti{
    int st;
    int end;
};
bool cmp(ti a,ti b){
    if(a.end==b.end)
        return a.st>b.st;
    else
    return a.end<b.end;
}
int main(){
    int n;
    cin>>n;
    vector<ti>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].st>>a[i].end;
    }
    int ans=0,end=0;
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++){
        if(a[i].st>=end){
            ans++;
            end=a[i].end;
        }
    }
    cout<<ans;
}