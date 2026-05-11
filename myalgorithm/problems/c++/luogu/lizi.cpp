#include<iostream>
using namespace std;
struct people{
    int num;
    string name;
};
int main(){
    ios::sync_with_stdio;
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int t1,t2;
    people a[100005];
    for(int i=0;i<n;i++){
        cin>>a[i].num>>a[i].name;
    }
    int index=0;
    for(int i=0;i<m;i++){
        cin>>t1>>t2;
        if(a[i].num==0){
            if(t1==1)
                index=(index+t2)%n;
            else
                index=index+n-(t2)%n;
        }
        else{
            if(t1==0)
                index=(index+t2)%n;
            else
                index=index+n-(t2)%n;
        }
    }   
    cout<<a[index].name<<endl;
}