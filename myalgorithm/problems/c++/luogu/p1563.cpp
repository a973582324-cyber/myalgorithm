#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int t1,t2;
    string name[100001];
    int num[100001];
    for(int i=0;i<n;i++){
     cin>>num[i]>>name[i];
    }
    int index=0;
    for(int i=0;i<m;i++){
        cin>>t1>>t2;
       if(num[index]==t1)
        {
            index-=t2;
            if(index<0)
            index+=n;
        }
        else
        {
            index+=t2;
            if(index>=n)
            index-=n;
        }
    }   
    cout<<name[index]<<endl;
    return 0;
}