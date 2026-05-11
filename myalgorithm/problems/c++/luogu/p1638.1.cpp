#include<iostream>
#include<queue>
using namespace std;
const int N=1000003;
int main(){
    int n,m;
    int num[N];
    int a[2003];
    int l,r,temp=1e6;
    queue<int>ans;
    int k=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(a[num[i]]==0){
            k++;
        }
        a[num[i]]++;
        ans.push(i);
        while(a[num[ans.front()]]>1&&!ans.empty()){
            a[num[ans.front()]]--;
            ans.pop();
        }
        if(k==m){
            if(ans.size()<temp){
                temp=ans.size();
                l=ans.front();
                r=ans.back();
            }
        }
    }
   cout<<l<<' '<<r;
}